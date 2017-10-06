using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace MapEditor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Map map = new Map();
        


        private void button1_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {

                //if (saveFileDialog1.FileName == null|| saveFileDialog1.FileName.Trim()=="") return;
                XmlWriterSettings writerSettings = new XmlWriterSettings()
                {
                    Indent = true,
                    IndentChars = "\t",
                    NewLineOnAttributes = true
                };

                using (XmlWriter writer = XmlWriter.Create(saveFileDialog1.FileName, writerSettings))
                {

                    writer.WriteStartDocument();

                    writer.WriteStartElement("Map");
                    writer.WriteAttributeString("columns", map.Cols.ToString());
                    writer.WriteAttributeString("rows", map.Rows.ToString());
                    writer.WriteAttributeString("tileWidth", map.TileWidth.ToString());
                    writer.WriteAttributeString("tileHeight", map.TileHeight.ToString());
                    writer.WriteAttributeString("imageSource", map.ImageSource);

                    //write the element Layer
                    writer.WriteStartElement("Layers");
                    foreach (var layer in map.Layers)
                    {
                        writer.WriteStartElement("Layer");
                        writer.WriteAttributeString("id", layer.Id.ToString());
                        writer.WriteAttributeString("order", layer.Order.ToString());
                        writer.WriteStartElement("TileSets");
                        foreach (var tileSet in layer.TileSets)
                        {
                            writer.WriteStartElement("TileSet");
                            writer.WriteAttributeString("id", tileSet.Id.ToString());
                            writer.WriteEndElement(); // end element TileSet
                        }
                        writer.WriteEndElement();
                        writer.WriteEndElement();
                    }
                    writer.WriteEndElement();// write end element Layers

                    

                    //write element Objects
                    writer.WriteStartElement("Objects");
                    foreach (var obj in map.Objects)
                    {
                        writer.WriteStartElement("Object");
                        writer.WriteAttributeString("id", obj.Id.ToString());
                        writer.WriteAttributeString("type", obj.Type.ToString());
                        writer.WriteAttributeString("name", obj.Name);
                        writer.WriteAttributeString("width", obj.Width.ToString());
                        writer.WriteAttributeString("height", obj.Height.ToString());
                        writer.WriteAttributeString("x", obj.X.ToString());
                        writer.WriteAttributeString("y", obj.Y.ToString());
                        foreach (var property in obj.Properties)
                        {
                            writer.WriteStartElement("Property");
                            writer.WriteAttributeString("id", property.Id.ToString());
                            writer.WriteAttributeString("name", property.Name);
                            writer.WriteAttributeString("type", property.Type);
                            writer.WriteAttributeString("DefaultValue", property.DefaultValue);
                            writer.WriteEndElement(); // end element Property
                        }
                        writer.WriteEndElement(); // end element Object
                    }
                    writer.WriteEndElement();// end element Objects
                    writer.WriteEndElement(); // end element Map
                }
                
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {

            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {

                XmlDocument doc = new XmlDocument();
                doc.Load(openFileDialog1.FileName);

                XmlNode node = doc.SelectSingleNode("/Map");
                map.LoadFromXML(node);
                
            }
            button1_Click(sender, e);
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
           
        }
    }
}




 