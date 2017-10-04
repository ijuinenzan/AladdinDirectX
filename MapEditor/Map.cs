using System;
using System.Collections.Generic;

public class Map
{
    private int _columns;
    private int _rows;
    private int _tileWidth;
    private int _tileHeight;

    private List<Layer> _layers;

    public Map Clone()
    {
        Map a = new Map();
        a._columns = _columns;
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

    public int Columns
    {
        get
        {
            return _columns;
        }
        set
        {
            _columns = value;
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
