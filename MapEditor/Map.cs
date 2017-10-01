using System;
using 

public class Map
{
    private int _width;
    private int _height;
    private int _tileWidth;
    private int _tileHeight;
    private TileSet[,] _tileSets;
    private Object[,] _objects;

    public Object[,] Objects
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

    public TileSet[,] TileSets
    {
        get
        {
            return _tileSets;
        }
        set
        {
            _tileSets = value;
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
