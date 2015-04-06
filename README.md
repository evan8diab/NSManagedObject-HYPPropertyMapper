# NSManagedObject-HYPPropertyMapper
[![Build Status](https://img.shields.io/travis/hyperoslo/NSManagedObject-HYPPropertyMapper.svg?style=flat)](https://travis-ci.org/hyperoslo/NSManagedObject-HYPPropertyMapper)

## Fill Core Data object with JSON

Mapping your Core Data objects with your JSON providing backend has never been this easy. 

```json
{
  "first_name": "John",
  "last_name": "Hyperseed"
}
```

``` objc
NSDictionary *values = [JSON valueForKey:@"user"];
[user hyp_fillWithDictionary:values];
```

Your Core Data entities should match your backend models but in `camelCase`. Your attributes should match their JSON counterparts. For example `first_name` maps to `firstName`, `address` to `address`.

There are two exceptions to this rule:

* `id`s should match `remoteID`
* Reserved attributes should be prefixed with the `entityName` (`type` becomes `userType`, `description` becomes `userDescription` and so on). In the JSON they don't need to change, you can keep `type` and `description` for example. A full list of reserved attributes can be found [here](https://github.com/hyperoslo/NSManagedObject-HYPPropertyMapper/blob/master/Source/NSManagedObject%2BHYPPropertyMapper.m#L265)

If you want to map your Core Data attribute with a JSON attribute that has different naming, you can do by adding `hyper.remoteKey` in the user info box with the value you want to map.

![Remote mapping documentation](https://raw.githubusercontent.com/hyperoslo/NSManagedObject-HYPPropertyMapper/master/Resources/userInfo_documentation.png)

## JSON representation from Core Data object

Getting a dictionary representation of your object is as easy as pie.

``` objc
UserManagedObject *user;
[user setValue:@"John" forKey:@"firstName"];
[user setValue:@"Hyperseed" forKey:@"lastName"];

NSDictionary *userValues = [user hyp_dictionary];
```

That's it, that's all you have to do, the keys will be magically transformed into a `snake_case` convention.

```json
{
  "first_name": "John",
  "last_name": "Hyperseed"
}
```

It supports relationships too, and we complain to the Rails rule `accepts_nested_attributes_for`, for example for a user that has many notes:

```json
"first_name": "John",
"last_name": "Hyperseed",
"notes_attributes": [
  {
    "0": {
      "id": 0,
      "text": "This is the text for the note A"
    },
    "1": {
      "id": 1,
      "text": "This is the text for the note B"
    }
  }
]
```

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## Credits

[Hyper](http://hyper.no) made this. We're a digital communications agency with a passion for good code,
and if you're using this library we probably want to hire you.

## License

NSManagedObject-HYPPropertyMapper is available under the MIT license. See the [LICENSE](https://raw.githubusercontent.com/hyperoslo/NSManagedObject-HYPPropertyMapper/master/LICENSE.md) file for more info.
