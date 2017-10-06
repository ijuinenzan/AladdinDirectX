using System;
using System.Collections.Generic;
using System.Xml;

public class Object
{
    private int _id;
    private int _width;
    private int _height;
    private int _x;
    private int _y;
    private string _name;
    private List<Property> _properties;
    private int _type;

    public Object Clone()
    {
        Object a = new Object();
        a._width = _width;
        a._height = _height;
        a._name = _name;
        a._x = _x;
        a._y = _y;
        a._type = _type;
        a._properties = _properties;
        a._id = _id;

        return a;
    }

    public void LoadFromXML(XmlNode node)
    {
        _id = int.Parse(node.Attributes["id"].Value);
        _name = node.Attributes["name"].Value;
        _height = int.Parse(node.Attributes["height"].Value);
        _width = int.Parse(node.Attributes["width"].Value);
        _type = int.Parse(node.Attributes["type"].Value);
        _x = int.Parse(node.Attributes["x"].Value);
        _y = int.Parse(node.Attributes["y"].Value);
        foreach (XmlNode subchild in node.ChildNodes)
        {
            Property property = new Property();
            Properties.Add(property);
            property.LoadFromXML(subchild);
        }
    }

    public Object()
    {
        _properties = new List<Property>();
    }

    public int Type
    {
        get
        {
            return _type;
        }
        set
        {
            _type = value;
        }
    }

    public int X
    {
        get
        {
            return _x;
        }
        set
        {
            _x = value;
        }
    }

    public int Y
    {
        get
        {
            return _y;
        }
        set
        {
            _y = value;
        }
    }

    public int Height
    {
        get
        {
            return _height;
        }
        set
        {
            _height = value;
        }
    }

    public int Width
    {
        get
        {
            return _width;
        }
        set
        {
            _width = value;
        }
    }

    public List<Property> Properties
    {
        get
        {
            return _properties;
        }
        set
        {
            _properties = value;
        }
    }


    public string Name
    {
        get
        {
            return _name;
        }
        set
        {
            _name = value;
        }
    }

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
