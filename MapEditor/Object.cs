using System;

public class Object
{
    private int _id;
    private int _row;
    private int _col;
    private string _name;
    private List<Property> _properties;

    public int Col
    {
        get
        {
            return _col;
        }
        set
        {
            _col = value;
        }
    }

    public int Row
    {
        get
        {
            return _row;
        }
        set
        {
            _row = value;
        }
    }

    public List<Property> Properties
    {
        get
        {
            return _properties;
        }
        set
        {
            _properties = value;
        }
    }


    public string Name
    {
        get
        {
            return _name;
        }
        set
        {
            _name = value;
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
