# barkeep::AtomicTraits


Trait class to extract underlying value type from numerics and std::atomics of numerics.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [T](api/Classes/classbarkeep_1_1_counter.md) | **[value_type](api/Classes/structbarkeep_1_1_atomic_traits.md#using-value_type)**  |


</span>

## Detailed Description

```cpp
template <typenameT >
struct barkeep::AtomicTraits;
```

Trait class to extract underlying value type from numerics and std::atomics of numerics. 
## Public Types Documentation

### using value_type

```cpp
using barkeep::AtomicTraits< T >::value_type =  T;
```


-------------------------------

Updated on 2024-02-18 at 11:29:07 -0500