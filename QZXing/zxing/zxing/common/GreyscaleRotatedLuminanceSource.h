// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef ZXING_GREYSCALE_ROTATED_LUMINANCE_SOURCE
#define ZXING_GREYSCALE_ROTATED_LUMINANCE_SOURCE
/*
 *  GreyscaleRotatedLuminanceSource.h
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <zxing/LuminanceSource.h>

namespace zxing {

class GreyscaleRotatedLuminanceSource : public LuminanceSource {
 private:
  typedef LuminanceSource Super;
  QSharedPointer<std::vector<zxing::byte>> greyData_;
  const int dataWidth_;
  const int left_;
  const int top_;

public:
  GreyscaleRotatedLuminanceSource(QSharedPointer<std::vector<zxing::byte>> greyData, int dataWidth, int dataHeight,
      int left, int top, int width, int height);

  QSharedPointer<std::vector<zxing::byte>> getRow(int y, QSharedPointer<std::vector<zxing::byte>> row) const;
  QSharedPointer<std::vector<zxing::byte>> getMatrix() const;
};

}

#endif // ZXING_GREYSCALE_ROTATED_LUMINANCE_SOURCE
