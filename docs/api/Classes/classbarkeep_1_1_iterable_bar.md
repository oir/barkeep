# barkeep::IterableBar


A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md)** <br>[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md)'s iterator class that wraps the container's iterator. When incremented, it increments the progress index.  |


</span>

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using std::atomic< size_t > </span>| <span class="codey">**[ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype)** </span> |
| <span class="codey">using [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< [ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype) > </span>| <span class="codey">**[ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype)** </span> |
| <span class="codey">using [ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md)< [ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype) > </span>| <span class="codey">**[Bar](api/Classes/classbarkeep_1_1_iterable_bar.md#using-bar)** </span> |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md#function-iterablebar)**(Container & container, const [IterableBarConfig](api/Classes/structbarkeep_1_1_iterable_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype) > & cfg = {})</span> |
| <span class="codey"> auto </span>|  <span class="codey">  **[begin](api/Classes/classbarkeep_1_1_iterable_bar.md#function-begin)**()</span> |
| <span class="codey"> auto </span>|  <span class="codey">  **[end](api/Classes/classbarkeep_1_1_iterable_bar.md#function-end)**()</span> |


</span>

## Detailed Description

```cpp
template <typename Container >
class barkeep::IterableBar;
```

A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop. 

[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md) starts the display not at the time of construction, but at the time of the first call to [begin()](api/Classes/classbarkeep_1_1_iterable_bar.md#function-begin). Thus, it is possible to set it up prior to loop execution.

Similarly, it ends the display not at the time of destruction, but at the first increment of the iterator past the end. Thus, even if the object stays alive after the loop, the display will be stopped. 

## Public Types Documentation

### using `ProgressType`

```cpp
using barkeep::IterableBar< Container >::ProgressType =  std::atomic<size_t>;
```


### using `ValueType`

```cpp
using barkeep::IterableBar< Container >::ValueType =  value_t<ProgressType>;
```


### using `Bar`

```cpp
using barkeep::IterableBar< Container >::Bar =  ProgressBarDisplay<ProgressType>;
```


## Public Functions Documentation

### function `IterableBar`

```cpp
inline IterableBar(
    Container & container,
    const IterableBarConfig< ValueType > & cfg = {}
)
```


### function `begin`

```cpp
inline auto begin()
```


### function `end`

```cpp
inline auto end()
```


-------------------------------