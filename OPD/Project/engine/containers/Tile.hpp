#ifndef TILE_H
#define TILE_H

#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class Tile : public Drawable {

    public:

      Tile();
      ~Tile();

      int getId();

      void setId(int value);
      void setPosition(float x, float y);
      void addTileRect(const IntRect &value);
      void setTilesetTexture(const Texture &value);
      void setOpacity(Uint8 value);
      void setVisible(bool value);

    private:
    
      int id;

      bool visible;
      Uint8 opacity;
      const Texture *tilesetTexture;
      Vertex vertices[4];
      IntRect tileRect;

      Transform transform;

      void updatePositions();
      void updateTexCoords();
      FloatRect getLocalBounds() const;
      FloatRect getGlobalBounds() const;

      void draw(RenderTarget &target, RenderStates states) const;

  };


}


#endif // TILE_H
