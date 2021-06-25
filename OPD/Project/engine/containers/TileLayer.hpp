#ifndef TILELAYER_H
#define TILELAYER_H


#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"
#include "Tile.hpp"


namespace engine {


  class TileLayer {

    public:

      TileLayer();
      ~TileLayer();

      void draw(RenderTarget &window) const;

      const string& getName();
      Uint8 getOpacity();

      void setName(const string &value);
      void setOpacity(Uint8 value);
      void setVisible(bool value);
      void addProperties(const map<string, string> &value);

      void addTile(Tile* tile);

    private:

      string name;

      bool visible;
      Uint8 opacity;

      vector<Tile*> tilesList;

      map<string, string> properties;

      void deleteData();

  };


}


#endif // TILELAYER_H
