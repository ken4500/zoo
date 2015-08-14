//
//  PurchaseDiamond200.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/13.
//
//

#ifndef Zoo_PurchaseDiamond200_h
#define Zoo_PurchaseDiamond200_h

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface PurchaseDiamond200 : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver>

- (void)requestPurchasing:(NSString *)productID;

@end

#endif
