using System;

public class Property
{
    private string _id;
    private string _name;
    private string _type;
    private string _defaultValue;

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
    public string Type
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
    public string DefaultValue
    {
        get
        {
            return _defaultValue;
        }
        set
        {
            _defaultValue = value;
        }
    }
}
