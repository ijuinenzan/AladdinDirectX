using System;
using System.Collections.Generic;

public class Object
{
    private int _id;
    private int _width;
    private int _height;
    private int _x;
    private int _y;
    private string _name;
    private List<Property> _properties;
    private int _type;

    public int Type
    {
        get
        {
            return _type;
        }
        set
        {
            _type = value;
        }
    }

    public int X
    {
        get
        {
            return _x;
        }
        set
        {
            _x = value;
        }
    }

    public int Y
    {
        get
        {
            return _y;
        }
        set
        {
            _y = value;
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
