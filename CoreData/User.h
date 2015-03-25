@import Foundation;
@import CoreData;

@class Company, Note;

@interface User : NSManagedObject

@property (nonatomic) NSNumber *age;
@property (nonatomic) NSDate *birthDate;
@property (nonatomic) NSNumber *contractID;
@property (nonatomic) NSDate *createdAt;
@property (nonatomic) NSString *driverIdentifier;
@property (nonatomic) NSString *firstName;
@property (nonatomic) NSString *ignoredParameter;
@property (nonatomic) NSString *lastName;
@property (nonatomic) NSNumber *numberOfAttendes;
@property (nonatomic) NSNumber *remoteID;
@property (nonatomic) NSDate *updatedAt;
@property (nonatomic) NSString *userDescription;
@property (nonatomic) NSString *userType;
@property (nonatomic) NSData *hobbies;
@property (nonatomic) Company *company;
@property (nonatomic) NSSet *notes;
@end

@interface User (CoreDataGeneratedAccessors)

- (void)addNotesObject:(Note *)value;
- (void)removeNotesObject:(Note *)value;
- (void)addNotes:(NSSet *)values;
- (void)removeNotes:(NSSet *)values;

@end
