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

#import "RMXRemixer.h"

@class RMXOverlayWindow;

NS_ASSUME_NONNULL_BEGIN

/**
 Internal API of Remixer.
 */
@interface RMXRemixer (Private)

/**
 Returns a Variable with the given key from the dictionary of Variables.
 @param key The key of the Variable.
 @return A Variable from the dictionary of Variables.
 */
+ (nullable RMXVariable *)variableForKey:(NSString *)key;

/**
 Adds a Variable to the dictionary of Variables stored by key.
 @param variable The Variable to be added.
 */
+ (__kindof RMXVariable *)addVariable:(RMXVariable *)variable;

/**
 Removes a Variable from the dictionary of Variables.
 @param variable The Variable to be removed.
 */
+ (void)removeVariable:(RMXVariable *)variable;

/**
 Removes a Variable with the given key from the dictionary of Variables.
 @param key The dictionary key of the Variable.
 */
+ (void)removeVariableWithKey:(NSString *)key;

/**
 Returns all Variables.
 @return All current Variables.
 */
+ (NSMapTable *)allVariables;

/**
 Removes all Variables and empties the dictionary of Variables.
 */
+ (void)removeAllVariables;

/**
 Saves the Variable using one of the storage options.
 @param variable The variable to save.
 */
+ (void)saveVariable:(RMXVariable *)variable;

/**
 Sets and saves the updated selectedValue and triggers a notification to update the control.
 @param value The new value that the variable should be set to.
 */
+ (void)updateVariable:(RMXVariable *)variable fromRemoteControllerToValue:(id)value;

/**
 Getter for the UIWindow used by the overlay.
 @return The UIWindow.
 */
+ (RMXOverlayWindow *)overlayWindow;

/**
 Refreshes the content of the overlay panel.
 */
+ (void)reloadControllers;

/**
 A unique session id. This is used for generating a URL for the remote controllers.
 @return The current session id.
 */
+ (NSString *)sessionId;

/**
 If you're using the Firebase version of Remixer, this URL points to the remote controller.
 Otherwise this returns null.
 @return The remote controller's URL.
 */
+ (nullable NSURL *)remoteControllerURL;

/**
 When set to YES, Remixer sends and receives updates from the remote controller.
 @param sharing Whether Remixer should be sharing variables through the remote controller.
 */
+ (void)setSharing:(BOOL)sharing;

/**
 Getter for the sharing property. YES means Remixer is sharing variables with the remote controller.
 @return Whether or not Remixer is currently sharing.
 */
+ (BOOL)isSharing;

@end

NS_ASSUME_NONNULL_END
