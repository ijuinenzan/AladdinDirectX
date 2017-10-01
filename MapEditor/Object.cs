using System;

public class Object
{
    private string _id;
    private string _name;
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
}
