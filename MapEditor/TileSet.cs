using System;

public class Class1
{
    private string _id;
    private string _path;
    private List<Property> _properties;


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

    public string Id
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
