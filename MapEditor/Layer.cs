using System;
using System.Collections.Generic;

public class Layer
{
    private List <TileSet> _tileSets;
    private List<Object> _objects;
    private int _id;
    private int _order;

    public Layer Clone()
    {
        Layer a = new Layer();
        a._tileSets = new List < TileSet > ();

        foreach (var tileset in _tileSets)
        {
            a._tileSets.Add(tileset.Clone (  ));
        }

        a._id = _id;
        a._order = _order;
        a._objects = _objects;
        return a;
    }

    public Layer()
    {
        _tileSets = new List < TileSet > ();
        _objects = new List<Object>();
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

    public List <TileSet> TileSets
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
