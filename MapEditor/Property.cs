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

    public Property LoadFromXML (XmlNode node)
    {
        if (node.HasChildNodes)
        {
            foreach (XmlNode child in node.ChildNodes)
            {
                this.Id = int.Parse(child.Attributes["id"].Value);
                this.Name = child.Attributes["name"].Value;
                this.Type = child.Attributes["type"].Value;
                this.DefaultValue = child.Attributes["defaultValue"].Value;

            }
            return this;
        }
        return null;
       
    }
}
