//
//  XFWireframe.h
//  XFLegoVIPER
//
//  Created by yizzuide on 15/12/22.
//  Copyright © 2015年 yizzuide. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XFWireFramePort.h"
#import "XFUIOperatorPort.h"

@interface XFRouting : NSObject <XFWireFramePort>

/**
 *  组装当前路由
 *
 *  @return 路由
 */
+ (instancetype)routing;

/**
 *  构建关系层
 *
 *  @param activityClass    视图层
 *  @param perstentClass    交互层
 *  @param interactorClass  业务层
 *  @param interactorClass  数据层
 *
 *  @return Routing
 */
- (instancetype)buildModulesAssemblyWithActivityClass:(Class)activityClass
                                       presenterClass:(Class)perstentClass
                                      interactorClass:(Class)interactorClass
                                     dataManagerClass:(Class)dataManagerClass;

/**
 *  构建关系层(视图从xib或storyboard中加载)
 *
 *  @param ibSymbol         使用字符串符号加载视图（xib:x-xibName,Storyboard:s-storyboardName-controllerIdentifier）
 *  @param perstentClass    交互层
 *  @param interactorClass  业务层
 *  @param dataManagerClass 数据层
 *
 *  @return Routing
 */
- (instancetype)buildModulesAssemblyWithIB:(NSString *)ibSymbol
                                       presenterClass:(Class)perstentClass
                                      interactorClass:(Class)interactorClass
                                     dataManagerClass:(Class)dataManagerClass;
/**
 *  构建关系层
 *
 *  @param activityClass    视图层
 *  @param navigatorClass   导航层
 *  @param perstentClass    交互层
 *  @param interactorClass  业务层
 *
 *  @return Routing
 */
- (instancetype)buildModulesAssemblyWithActivityClass:(Class)activityClass
                                       navigatorClass:(Class)navigatorClass
                                       presenterClass:(Class)perstentClass
                                      interactorClass:(Class)interactorClass
                                     dataManagerClass:(Class)dataManagerClass;

/**
 *  获得UI事件处理层（Presenter）
 */
@property (nonatomic, weak, readonly) id<XFUIOperatorPort> uiOperator;

/**
 *  获得当前真实存在的视图
 *
 *  @return 视图
 */
- (__kindof id<XFUserInterfacePort>)realInterface;
/**
 *  获得包装当前视图的导航
 *
 *  @return 导航
 */
- (__kindof UINavigationController *)realNavigator;

/**
 *  在主窗口显示第一个视图
 *
 *  @param mainWindow             主窗口
 */
- (void)showRootActivityOnWindow:(UIWindow *)mainWindow;


/**
 *  推入一个新的路由
 *
 *  @param nextRouting  下一个路由
 *  @param intentData   意图数据（没有可以传nil）
 */
- (void)pushRouting:(XFRouting *)nextRouting intent:(id)intentData;

/**
 *  Modal一个新的路由
 *
 *  @param nextRouting  下一个路由
 *  @param intentData   意图数据（没有可以传nil）
 */
- (void)presentRouting:(XFRouting *)nextRouting intent:(id)intentData;

/**
 *  自定义推入路由界面切换
 *
 *  @param nextRouting    下一个路由
 *  @param trasitionBlock 视图切换代码
 *  @param intentData     意图数据（没有可以传nil）
 */
- (void)addRouting:(XFRouting *)nextRouting withTrasitionBlock:(void(^)())trasitionBlock intent:(id)intentData;

/**
 *  push一个MVx架构里的控制器（注意：它不会被VIPER路由器管理，所以不能对之发VIPER事件通信）
 *
 */
- (void)pushMVxViewController:(UIViewController *)viewController;
/**
 *  present一个MVx架构里的控制器（注意：它不会被VIPER路由器管理，所以不能对之发VIPER事件通信）
 *
 */
- (void)presentMVxViewContrller:(UIViewController *)viewController;
@end
