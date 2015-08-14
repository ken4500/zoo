//
//  PurchaseDiamond200.m
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/13.
//
//


#import "PurchaseDiamond200.h"
#import "UserDataManager.h"
#import "Constants.h"
#import "PurchaseBridge.h"
#import "SceneManager.h"
#import "MainScene.h"

@implementation PurchaseDiamond200

- (void)requestPurchasing:(NSString *)productID
{
    // インジケーターの表示
    PurchaseBridge::showIdicator();

    if (![SKPaymentQueue canMakePayments]) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"エラー"
                                                        message:@"アプリ内課金が制限されています。"
                                                       delegate:nil
                                              cancelButtonTitle:nil
                                              otherButtonTitles:@"OK", nil];
        [alert show];
        return;
    }
    
    [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
    
    NSSet *productIDs = [NSSet setWithObject:productID];
    SKProductsRequest *productRequest = [[SKProductsRequest alloc] initWithProductIdentifiers:productIDs];
    productRequest.delegate = self;
    [productRequest start];
}

- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response
{
    for (SKProduct *product in response.products) {
        SKPayment *payment = [SKPayment paymentWithProduct:product];
        [[SKPaymentQueue defaultQueue] addPayment:payment];
        NSLog(@"product id = %@",product.productIdentifier);
    }
}

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions
{
    MainScene* scene;
    for (SKPaymentTransaction *transaction in transactions) {
        switch (transaction.transactionState) {
            case SKPaymentTransactionStatePurchasing:
                // 購入中の処理
                break;
            case SKPaymentTransactionStatePurchased:
                // 購入成功時の処理
                UserDataManager::getInstance()->addDiamondNum(200);
                [queue finishTransaction:transaction];
                PurchaseBridge::hideIdicator();
                scene = SceneManager::getInstance()->getMainScene();
                if (scene) {
                    scene->updateDiamondLabel();
                }
                break;
            case SKPaymentTransactionStateRestored:
                // リストア時の処理
                UserDataManager::getInstance()->addDiamondNum(200);
                [queue finishTransaction:transaction];
                PurchaseBridge::hideIdicator();
                scene = SceneManager::getInstance()->getMainScene();
                if (scene) {
                    scene->updateDiamondLabel();
                }
                break;
            case SKPaymentTransactionStateFailed:
            default:
                // 購入失敗時の処理
                [queue finishTransaction:transaction];
                PurchaseBridge::hideIdicator();
                break;
        }
    }
}

@end
