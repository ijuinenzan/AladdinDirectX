using System;

public class TileSet
{
    private int _id;
    private int _layerId;


    public int LayerId
    {
        get
        {
            return _layerId;
        }
        set
        {
            _layerId = value;
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
