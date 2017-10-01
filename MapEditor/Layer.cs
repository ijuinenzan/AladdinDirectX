using System;
using System.Collections.Generic;

public class Layer
{
    private Dictionary<int, TileSet> _tileSets;
    private List<Object> _objects;

    private int _order;


    public int Order
    {
        get
        {
            return _order;
        }
        set
        {
            _order = value;
        }
    }

    public Dictionary<int, TileSet> TileSets
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
}
