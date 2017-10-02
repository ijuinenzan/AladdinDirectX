using System;
using System.Collections.Generic;

public class Map
{
    private int _columns;
    private int _rows;
    private int _tileWidth;
    private int _tileHeight;

    private List<Layer> _layers;

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
