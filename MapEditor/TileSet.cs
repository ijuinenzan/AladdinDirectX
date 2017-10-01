using System;

public class Class1
{
    private int _id;
    private string _path;
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

    public string Path
    {
        get
        {
            return _path;
        }
        set
        {
            _path = value;
        }
    }
}
