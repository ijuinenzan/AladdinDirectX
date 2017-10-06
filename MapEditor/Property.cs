using System;
using System.Xml;
using System.Collections.Generic;

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

    public void LoadFromXML (XmlNode node)
    {

        this.Id = int.Parse(node.Attributes["id"].Value);
        this.Name = node.Attributes["name"].Value;
        this.Type = node.Attributes["type"].Value;
        this.DefaultValue = node.Attributes["defaultValue"].Value;   
    }
}
