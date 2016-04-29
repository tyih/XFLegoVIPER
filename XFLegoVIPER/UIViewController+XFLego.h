//
//  UIViewController+XFLego.h
//  CreativeButton
//
//  Created by yizzuide on 16/2/24.
//  Copyright © 2016年 RightBrain-Tech. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XFUserInterfaceProt.h"

@protocol XFEventHandlerProt;

@interface UIViewController (XFLego) <XFUserInterfaceProt>

@property (nonatomic, strong) id<XFEventHandlerProt> eventHandler;
@end