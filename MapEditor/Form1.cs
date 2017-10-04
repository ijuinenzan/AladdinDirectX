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
        Img image = new Img();
        Layer layer = new Layer();


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
                    //writer.WriteString("\n");
                    //write the root "Map"
                    writer.WriteStartElement("Map");
                    writer.WriteAttributeString("columns", map.Cols.ToString());
                    writer.WriteAttributeString("rows", map.Rows.ToString());
                    writer.WriteAttributeString("tileWidth", map.TileWidth.ToString());
                    writer.WriteAttributeString("tileHeight", map.TileHeight.ToString());
                    //writer.WriteEnd();
                    //write the element Image
                    writer.WriteStartElement("Image");
                    writer.WriteAttributeString("path", image.Path);

                    //write the element TileSet
                    Dictionary<int, TileSet>.KeyCollection keyCollection = layer.TileSets.Keys;

                    foreach (var key in keyCollection)
                    {
                        writer.WriteStartElement("TileSet");
                        writer.WriteAttributeString("id=", key.ToString());
                        writer.WriteEndElement(); //end the element TileSet
                    }
                    writer.WriteEndElement(); //end the element Image

                    //write the element Layer
                    foreach (var layer in map.Layers)
                    {
                        writer.WriteStartElement("Layer");
                        writer.WriteAttributeString("order=", layer.Order.ToString());

                        //write MatrixIndex
                        writer.WriteStartElement("MatrixIndex");
                        for (int i = 0; i < map.Rows; i++)
                        {
                            writer.WriteStartElement("Row");
                            writer.WriteAttributeString("id=", i.ToString());
                            Dictionary<int, TileSet>.ValueCollection tileSetCollection = layer.TileSets.Values;
                            foreach (var tileSet in layer.TileSets)
                            {
                                if (tileSet.Value.LayerId == i)
                                {

                                }
                            }
                            writer.WriteEndElement(); //  end the element Row
                        }
                        writer.WriteEndElement(); // end the element MatrixIndex

                        //write element Objects
                        writer.WriteStartElement("Objects");
                        foreach (var obj in layer.Objects)
                        {
                            writer.WriteStartElement("Object");
                            writer.WriteAttributeString("id=", obj.Id.ToString());
                            writer.WriteAttributeString("type=", obj.Type.ToString());
                            writer.WriteAttributeString("name=", obj.Name);
                            writer.WriteAttributeString("width=", obj.Width.ToString());
                            writer.WriteAttributeString("height=", obj.Height.ToString());
                            writer.WriteAttributeString("x=", obj.X.ToString());
                            writer.WriteAttributeString("y=", obj.Y.ToString());
                            foreach (var property in obj.Properties)
                            {
                                writer.WriteStartElement("Property");
                                writer.WriteAttributeString("id=", property.Id.ToString());
                                writer.WriteAttributeString("name=", property.Name);
                                writer.WriteAttributeString("type=", property.Type);
                                writer.WriteAttributeString("DefaultValue=", property.DefaultValue);
                                writer.WriteEndElement(); // end element Property
                            }
                            writer.WriteEndElement(); // end element Object
                        }
                        writer.WriteEndElement();// end element Objects
                        writer.WriteEndElement();// end element Layer
                    }
                    writer.WriteEndElement(); // end element Map
                    writer.WriteEndDocument();
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

                //take info Map
                XmlNode xmlMap = doc.SelectSingleNode("/Map");
                Map map = new Map();
                map.Cols = int.Parse(xmlMap.Attributes["columns"].Value.ToString());
                map.Rows = int.Parse(xmlMap.Attributes["rows"].Value.ToString());
                map.TileWidth = int.Parse(xmlMap.Attributes["tileWidth"].Value.ToString());
                map.TileHeight = int.Parse(xmlMap.Attributes["tileHeight"].Value.ToString());

                //take info TileSet
                XmlNodeList xmlLayer = doc.SelectNodes("/Layer");
                XmlNode xmlImage = doc.SelectSingleNode("/Map/Image");
                string path = xmlImage.Attributes["path"].Value.ToString();

                //XmlNodeList xmlTilesetImage = doc.SelectSingleNode("/map/tileset/image");
                //string name = xmlTilesetImage.Attributes["source"].Value.ToString();
                //string[] arrSource = openFileDialog1.FileName.Split(new String[] { "\\" }, StringSplitOptions.RemoveEmptyEntries);
                //arrSource[arrSource.Length - 1] = name;
                //string source = "";
                //for (int i = 0; i < arrSource.Length; i++)
                //{
                //    source += arrSource[i] + (i == (arrSource.Length - 1) ? "" : "\\");
                //}
                //tileset = new TileSet(name, source, int.Parse(xmlTileset.Attributes["tilewidth"].Value.ToString()), int.Parse(xmlTileset.Attributes["tileheight"].Value.ToString()));
                //int width = int.Parse(xmlMap.Attributes["width"].Value.ToString());
                //int height = int.Parse(xmlMap.Attributes["height"].Value.ToString());
                //background = new Background(tileset, width, height);
                //XmlNodeList arrBackground = doc.SelectNodes("/map/layer/data/tile");
                //for (int i = 0; i < background.MapHeight; i++)
                //    for (int j = 0; j < background.MapWidth; j++)
                //    {
                //        XmlNode tileId = arrBackground.Item(i * background.MapWidth + j).Attributes["gid"];
                //        background[i, j] = int.Parse(tileId.Value.ToString());
                //    }
                //UpdatePanelTileSet();
                ////try
                ////{
                //XmlNodeList objects = doc.SelectNodes("/map/objectgroup/object");
                //if (objects.Count > 0)
                //{
                //    listObject.Clear();
                //    lstObject.Items.Clear();
                //    proObject.SelectedObject = null;
                //    foreach (XmlNode obj in objects)
                //    {
                //        Objects newObject = new Objects(int.Parse(obj.Attributes["id"].Value), obj.Attributes["name"].Value, int.Parse(obj.Attributes["type"].Value), float.Parse(obj.Attributes["x"].Value), float.Parse(obj.Attributes["y"].Value), float.Parse(obj.Attributes["width"].Value), float.Parse(obj.Attributes["height"].Value));
                //        if (obj.HasChildNodes)
                //        {
                //            XmlNodeList properties = obj.ChildNodes[0].ChildNodes;
                //            if (properties.Count > 0)
                //            {
                //                foreach (XmlNode attribute in properties)
                //                {
                //                    newObject.Property.Add(attribute.Attributes["name"].Value, attribute.Attributes["value"].Value);
                //                }
                //            }
                //        }
                //        listObject.Add(newObject);
                //        UpdateListObject(newObject);
                //    }
                //    Objects.count = int.Parse(objects.Item(objects.Count - 1).Attributes["id"].Value) + 1;
                //}
                ////}
                ////catch (NullReferenceException)
                ////{
                ////    MessageBox.Show("Map nay chua co object");
                ////}
                //Draw();

            }
        }

    }
}




 