using System;

public class Property
{
    private int _id;
    private string _name;
    private string _type;
    private string _defaultValue;

    public Property Clone()
    {
        Property a = new Property();
        a._name = _name;
        a._type = _type;
        a._id = _id;
        a._defaultValue = _defaultValue;
        return a;
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
