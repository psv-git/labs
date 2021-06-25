#ifndef OBJECT_H
#define OBJECT_H

#include "../global/EngineHeaders.hpp"
#include "../global/EngineConstants.hpp"


namespace engine {


  class Object : public Drawable {

    public:

      Object();
      ~Object();

      void copyTo(Object *object);

      int getId();
      const string& getName();
      const string& getType();
      const Transform& getTransform();

      void setId(int value);
      void setName(const string &value);
      void setType(const string &value);

      void setMovable(bool value);
      void setGravity(Uint8 value);
      void setPosition(const Vector2f &value);
      void setPosition(float x, float y);
      void setRotation(float value);
      void setTransform(const Transform &value);

      void setVisible(bool value);
      void setOpacity(Uint8 value);
      void addTileRect(const pair<IntRect, float> &value);
      void setTilesetTexture(const Texture &value);

      void addProperties(const map<string, string> &value);

    private:
    
      int id;
      string name;
      string type;

      bool movable;
      Uint8 gravity;
      Vector2f position;
      float rotation;
      Transform transform;

      bool visible;
      Uint8 opacity;
      const Texture *tilesetTexture;
      Vertex vertices[4];
      IntRect tileRect;
      vector<pair<IntRect, float>> tilesRectList;

      map<string, string> properties;

      void changeTileRect(int index);
      void updatePositions();
      void updateTexCoords();
      FloatRect getLocalBounds() const;
      FloatRect getGlobalBounds() const;

      void draw(RenderTarget &target, RenderStates states) const;

  };


}


#endif // OBJECT_H
