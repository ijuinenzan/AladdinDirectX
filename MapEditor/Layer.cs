using System;

public class Layer
{
    private Dictionary<int, TileSet> _tileSets;
    private List<Object> _objects;

    private int _order;
    private int _mapId;

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
    public int MapId
    {
        get
        {
            return _mapId;
        }
        set
        {
            _mapId = value;
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
