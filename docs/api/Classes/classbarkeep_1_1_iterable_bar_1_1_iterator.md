# barkeep::IterableBar::Iterator





`#include <barkeep.h>`

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-iterator)**(typename Container::iterator it, [ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype) & idx)</span> |
| <span class="codey"> [Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & </span>|  <span class="codey">  **[operator++](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator++)**()</span> |
| <span class="codey"> bool </span>|  <span class="codey">  **[operator!=](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator!=)**(const [Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & other) const</span> |
| <span class="codey"> auto & </span>|  <span class="codey">  **[operator*](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator*)**()</span> |


</span>

## Public Functions Documentation

### function `Iterator`

```cpp
inline Iterator(
    typename Container::iterator it,
    ProgressType & idx
)
```


### function `operator++`

```cpp
inline Iterator & operator++()
```


### function `operator!=`

```cpp
inline bool operator!=(
    const Iterator & other
) const
```


### function `operator*`

```cpp
inline auto & operator*()
```


-------------------------------

Updated on 2024-04-03 at 21:24:10 -0400