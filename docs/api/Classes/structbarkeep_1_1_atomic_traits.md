# barkeep::AtomicTraits


Trait class to extract underlying value type from numerics and std::atomics of numerics.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using T | **[value_type](api/Classes/structbarkeep_1_1_atomic_traits.md#using-value_type)**  |


</span>

## Detailed Description

```cpp
template <typename T >
struct barkeep::AtomicTraits;
```

Trait class to extract underlying value type from numerics and std::atomics of numerics. 
## Public Types Documentation

### using value_type

```cpp
using barkeep::AtomicTraits< T >::value_type =  T;
```


-------------------------------

Updated on 2024-03-28 at 22:58:08 -0400