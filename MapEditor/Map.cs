using System;
using System.Collections.Generic;

using MapEditor;

public class Map
{
    private int _cols;
    private int _rows;
    private int _tileWidth;
    private int _tileHeight;
    private Img _img;

    private List<Layer> _layers;

    public Img Img
    {
        get
        {
            return _img;
        }
        set
        {
            _img = value;
        }
    }

    public Map Clone()
    {
        Map a = new Map();
        a._cols = _cols;
        a._rows = _rows;
        a._tileHeight = _tileHeight;
        a._tileWidth = _tileWidth;
        a._layers = new List<Layer>();
        foreach (var layer in _layers)
        {
            a._layers.Add(layer.Clone());
        }
        return a;
    }

    public Map()
    {
        _layers = new List<Layer>();
        _img = new Img (  );
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
}
