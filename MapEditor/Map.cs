using System;
using System.Collections.Generic;

public class Map
{
    private int _width;
    private int _height;
    private int _tileWidth;
    private int _tileHeight;

    private List<Layer> _layers;

    public Map Clone()
    {
        Map a = new Map();
        a._width = _width;
        a._height = _height;
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
