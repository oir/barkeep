# barkeep::IterableBar::Iterator




## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-iterator)**([typename](api/Classes/classbarkeep_1_1_counter.md) Container::iterator it, ProgressType & idx) |
| [Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & | **[operator++](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator++)**() |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[operator!=](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator!=)**([const](api/Classes/classbarkeep_1_1_counter.md)[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & other) const |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[operator*](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator*)**() |


</span>

## Public Functions Documentation

### function Iterator

```cpp
inline Iterator(
    typename Container::iterator it,
    ProgressType & idx
)
```


### function operator++

```cpp
inline Iterator & operator++()
```


### function operator!=

```cpp
inline bool operator!=(
    constIterator & other
) const
```


### function operator*

```cpp
inline auto & operator*()
```


-------------------------------

Updated on 2024-02-19 at 09:47:42 -0500