//
//  PurchaseBridge.mm
//  ninjya
//
//  Created by Ken Watanabe on 2015/04/13.
//
//

#import "PurchaseBridge.h"
#import "PurchaseDiamond200.h"
#import "MBProgressHUD.h"

void PurchaseBridge::requestPurchaseDiamond200()
{
    [[[PurchaseDiamond200 alloc] init] requestPurchasing:[NSString stringWithUTF8String:"com.kenwatanabe.zoo.diamond200"]];
}

void PurchaseBridge::showIdicator()
{
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (topController.presentedViewController) {
        topController = topController.presentedViewController;
    }
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:topController.view animated:YES];
    hud.dimBackground = YES;
    topController.view.userInteractionEnabled = NO;
}

void PurchaseBridge::hideIdicator()
{
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (topController.presentedViewController) {
        topController = topController.presentedViewController;
    }
    [MBProgressHUD hideHUDForView:topController.view animated:YES];
    topController.view.userInteractionEnabled = YES;
}
