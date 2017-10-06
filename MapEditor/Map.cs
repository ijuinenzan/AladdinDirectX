using System;
using System.Collections.Generic;
using System.Xml;

using MapEditor;

public class Map
{
    private int _cols;
    private int _rows;
    private int _tileWidth;
    private int _tileHeight;
    private string _imageSource;

    private List<Object> _objects;
    private List<Layer> _layers;

    public string ImageSource
    {
        get
        {
            return _imageSource;
        }
        set
        {
            _imageSource = value;
        }
    }

    public Map Clone()
    {
        Map a = new Map();
        a._imageSource = _imageSource;
        a._cols = _cols;
        a._rows = _rows;
        a._tileHeight = _tileHeight;
        a._tileWidth = _tileWidth;
        a._layers = new List<Layer>();
        a._objects = _objects;
        foreach (var layer in _layers)
        {
            a._layers.Add(layer.Clone());
        }
        return a;
    }

    public Map()
    {
        _layers = new List<Layer>();
        _objects = new List<Object>();
    }

    public List<Object> Objects
    {
        get
        {
            return _objects;
        }
        set
        {
            _objects = value;
        }
    }

    public List<Layer> Layers
    {
        get
        {
            return _layers;
        }
        set
        {
            _layers = value;
        }
    }

    public int Cols
    {
        get
        {
            return _cols;
        }
        set
        {
            _cols = value;
        }
    }

    public int Rows
    {
        get
        {
            return _rows;
        }
        set
        {
            _rows = value;
        }
    }

    public int TileWidth
    {
        get
        {
            return _tileWidth;
        }
        set
        {
            _tileWidth = value;
        }
    }

    public int TileHeight
    {
        get
        {
            return _tileHeight;
        }
        set
        {
            _tileHeight = value;
        }
    }

    public void LoadFromXML(XmlNode node)
    {
        this.Cols = int.Parse(node.Attributes["columns"].Value.ToString());
        this.Rows = int.Parse(node.Attributes["rows"].Value.ToString());
        this.TileWidth = int.Parse(node.Attributes["tileWidth"].Value.ToString());
        this.TileHeight = int.Parse(node.Attributes["tileHeight"].Value.ToString());
        this.ImageSource = node.Attributes["imageSource"].Value;

        if (node.HasChildNodes)
        {
            XmlNodeList layerList = node.SelectNodes("/Map/Layers");
            foreach (XmlNode child in layerList)
            {
                Layer layer = new Layer();
                this.Layers.Add(layer.LoadFromXML(child));
            }
            
            XmlNodeList objectList = node.SelectNodes("/Map/Objects");
            foreach (XmlNode child in objectList)
            {
                Object obj = new Object();
                this.Objects.Add(obj.LoadFromXML(child));
            }
        }
    }

    public void WriteMap(XmlWriter writer)
    {

    }

}
