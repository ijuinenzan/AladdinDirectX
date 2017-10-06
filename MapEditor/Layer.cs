using System;
using System.Collections.Generic;
using System.Xml;

public class Layer
{
    private List <TileSet> _tileSets;
    private int _id;
    private int _order;

    public Layer Clone()
    {
        Layer a = new Layer();
        a._tileSets = new List < TileSet > ();

        foreach (var tileset in _tileSets)
        {
            a._tileSets.Add(tileset.Clone (  ));
        }

        a._id = _id;
        a._order = _order;
        return a;
    }

    public void LoadFromXML(XmlNode node)
    {
        _id = int.Parse(node.Attributes["id"].Value);
        _order = int.Parse(node.Attributes["order"].Value);
        foreach (XmlNode subChild in node.FirstChild.ChildNodes)
        {
            TileSet tileSet = new TileSet();
            tileSet.LoadFromXML(subChild);
            TileSets.Add(tileSet);
        }
    }

    public Layer()
    {
        _tileSets = new List < TileSet > ();
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

    public int Order
    {
        get
        {
            return _order;
        }
        set
        {
            _order = value;
        }
    }

    public List <TileSet> TileSets
    {
        get
        {
            return _tileSets;
        }
        set
        {
            _tileSets = value;
        }
    }
}
