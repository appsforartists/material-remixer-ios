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

#import <Foundation/Foundation.h>

#import "RMXRemix.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The RMXRemixer class is a Singleton class that keeps track of all the Remixes and deals with
 saving/syncing its values.
 */
@interface RMXRemixer : NSObject <RMXRemixDelegate>

/**
 Returns a remix with the given key from the dictionary of remixes.
 @param key The key of the remix.
 @return A remix from the dictionary of remixes.
 */
+ (nullable RMXRemix *)remixForKey:(NSString *)key;

/**
 Adds a remix to the dictionary of remixes stored by key.
 @param remix The remix to be added.
 */
+ (void)addRemix:(RMXRemix *)remix;

/**
 Removes a remix from the dictionary of remixes.
 @param remix The remix to be removed.
 */
+ (void)removeRemix:(RMXRemix *)remix;

/**
 Removes a remix with the given key from the dictionary of remixes.
 @param key The dictionary key of the remix.
 */
+ (void)removeRemixWithKey:(NSString *)key;

/**
 Returns all remixes.
 @return An array of all current remixes.
 */
+ (NSArray<RMXRemix *> *)allRemixes;

/** Removes all remixes and empties the dictionary of remixes. */
+ (void)removeAllRemixes;

#pragma mark - RMXRemixDelegate

- (void)remix:(RMXRemix *)remix wasUpdatedFromOverlayToValue:(id)value;

@end

NS_ASSUME_NONNULL_END
