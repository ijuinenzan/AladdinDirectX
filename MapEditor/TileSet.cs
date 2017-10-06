using System;
using System.Drawing;
using System.Xml;

public class TileSet
{
    private int _id;
    //private Image _image;

    public TileSet Clone()
    {
        TileSet a = new TileSet();
        //a._image = (Image)_image.Clone();
        a._id = _id;

        return a;
    }

    public void LoadFromXML(XmlNode node)
    {
        this.Id = int.Parse(node.Attributes["id"].Value);
    }


    //public Image Image
    //{
    //    get
    //    {
    //        return _image;
    //    }
    //    set
    //    {
    //        _image = value;
    //    }
    //}

    public int Id
    {
        get
        {
            return _id;
        }
        set
        {
            _id = value;
        }
    }
}
