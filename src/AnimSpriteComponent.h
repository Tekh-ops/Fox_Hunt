#pragma once

#include "SpriteComponent.h"
#include <string>
#include <vector>
#include <unordered_map>

struct AnimationClip {
  std::string name;
  int startFrame;
  int endFrame;
  bool isLooping;
};

class AnimSpriteComponent : public SpriteComponent
{
private:
  std::vector<SDL_Texture*> m_AnimTextures;
  std::unordered_map<std::string, AnimationClip> m_AnimationClips;
  std::string m_CurrentAnimationClip;
  std::string m_PreviousAnimationClip;
  float m_CurrentFrame;
  float m_AnimFPS;
public:
  AnimSpriteComponent(class Actor* owner, int drawOrder = 100);
  void Update(float deltaTime) override;
  void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
  void SetAnimationClip(std::string name, int startFrame, int endFrame, bool isLooping);

  void SetCurrentAnimation(std::string name);
  float GetAnimFPS() const;
  void SetAnimFPS(float fps);
};
