# barkeep::IterableBar


A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md)**  |


</span>

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using std::atomic< size_t > | **[ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype)**  |
| using [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< [ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype) > | **[ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype)**  |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md#function-iterablebar)**(Container & container, const [IterableBarConfig](api/Classes/structbarkeep_1_1_iterable_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype) > & cfg ={}) |
| auto | **[begin](api/Classes/classbarkeep_1_1_iterable_bar.md#function-begin)**() |
| auto | **[end](api/Classes/classbarkeep_1_1_iterable_bar.md#function-end)**() |


</span>

## Detailed Description

```cpp
template <typename Container >
class barkeep::IterableBar;
```

A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop. 
## Public Types Documentation

### using ProgressType

```cpp
using barkeep::IterableBar< Container >::ProgressType =  std::atomic<size_t>;
```


### using ValueType

```cpp
using barkeep::IterableBar< Container >::ValueType =  value_t<ProgressType>;
```


## Public Functions Documentation

### function IterableBar

```cpp
inline IterableBar(
    Container & container,
    const IterableBarConfig< ValueType > & cfg ={}
)
```


### function begin

```cpp
inline auto begin()
```


### function end

```cpp
inline auto end()
```


-------------------------------

Updated on 2024-03-28 at 22:58:08 -0400