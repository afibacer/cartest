/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_TOOLS_VISUALIZER_FREECAMERA_H_
#define MODULES_TOOLS_VISUALIZER_FREECAMERA_H_

#include "modules/tools/visualizer/abstract_camera.h"

class FreeCamera : public AbstractCamera {
 public:
  explicit FreeCamera(void);
  ~FreeCamera() {}

  // After calling the function updateWorld
  // the translation become zero vector
  virtual void UpdateWorld(void);

  const QVector3D& tanslation(void) { return translation_; }
  void set_translation(const QVector3D& t) { translation_ = t; }

  void Walk(const float dt) { translation_ += (look_ * dt); }
  void Starfe(const float dt) { translation_ += (right_ * dt); }
  void Lift(const float dt) { translation_ += (up_ * dt); }

 private:
  QVector3D translation_;
};

#endif  // MODULES_TOOLS_VISUALIZER_FREECAMERA_H_
