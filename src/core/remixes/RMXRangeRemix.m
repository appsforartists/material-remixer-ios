/*
 Copyright 2016-present Google Inc. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "RMXRangeRemix.h"

#import "RMXRemixer.h"

@implementation RMXRangeRemix

+ (instancetype)addRangeRemixWithKey:(NSString *)key
                        defaultValue:(CGFloat)defaultValue
                            minValue:(CGFloat)minValue
                            maxValue:(CGFloat)maxValue
                           increment:(CGFloat)increment
                         updateBlock:(RMXRangeUpdateBlock)updateBlock {
  RMXRangeRemix *remix = [[self alloc] initWithKey:key
                                      defaultValue:defaultValue
                                          minValue:minValue
                                          maxValue:maxValue
                                         increment:increment
                                       updateBlock:updateBlock];
  [RMXRemixer addRemix:remix];
  return remix;
}

+ (instancetype)addRangeRemixWithKey:(NSString *)key
                        defaultValue:(CGFloat)defaultValue
                            minValue:(CGFloat)minValue
                            maxValue:(CGFloat)maxValue
                         updateBlock:(RMXRangeUpdateBlock)updateBlock {
  return [self addRangeRemixWithKey:key
                       defaultValue:defaultValue
                           minValue:minValue
                           maxValue:maxValue
                          increment:0
                        updateBlock:updateBlock];
}

- (instancetype)initWithKey:(NSString *)key
               defaultValue:(CGFloat)defaultValue
                   minValue:(CGFloat)minValue
                   maxValue:(CGFloat)maxValue
                  increment:(CGFloat)increment
                updateBlock:(RMXRangeUpdateBlock)updateBlock {
  self = [super initWithKey:key
             typeIdentifier:RMXTypeRange
               defaultValue:@(defaultValue)
                updateBlock:^(RMXRemix *_Nonnull remix, id _Nonnull selectedValue) {
                  updateBlock(remix, [selectedValue floatValue]);
                }];
  if (self) {
    _minimumValue = minValue;
    _maximumValue = maxValue;
    _increment = increment;
    self.controlType = increment > 0 ? RMXControlTypeStepper : RMXControlTypeSlider;
  }
  return self;
}

- (NSDictionary *)toJSON {
  NSMutableDictionary *json = [super toJSON];
  json[@"minimumValue"] = @(self.minimumValue);
  json[@"maximumValue"] = @(self.maximumValue);
  json[@"stepValue"] = @(self.increment);
  return json;
}

@end
