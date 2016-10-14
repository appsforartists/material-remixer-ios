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

#import "RMXVariable.h"

@class RMXStringVariable;

NS_ASSUME_NONNULL_BEGIN

/** RMXStringUpdateBlock is a block that will be invoked when a string Variable is updated. */
typedef void (^RMXStringUpdateBlock)(RMXStringVariable *variable, NSString *selectedValue);

@interface RMXStringVariable : RMXVariable

/** The selected value of this Variable */
@property(nonatomic, strong) NSString *selectedValue;

/** If set, these are the only values this Variable can take. */
@property(nonatomic, strong) NSArray<NSString *> *possibleValues;

/** Convenience initializer for Variables that are stored in the cloud. */
+ (instancetype)stringVariableWithKey:(NSString *)key updateBlock:(RMXStringUpdateBlock)updateBlock;

/**
 * Initializer for Variables that are not defined in the cloud. If you're using the cloud mode
 * these properties will be overriden if they differ from what's stored there.
 */
+ (instancetype)stringVariableWithKey:(NSString *)key
                         defaultValue:(NSString *)defaultValue
                       possibleValues:(NSArray<NSString *> *)possibleValues
                          updateBlock:(RMXStringUpdateBlock)updateBlock;

@end

NS_ASSUME_NONNULL_END
