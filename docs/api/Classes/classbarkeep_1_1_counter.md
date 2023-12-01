# barkeep::Counter


 [More...](#detailed-description)

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(Progress * progress, std::ostream & out =std::cout) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(const [Counter](api/Classes/classbarkeep_1_1_counter.md)< Progress > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< Progress > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |
| virtual void | **[show](api/Classes/classbarkeep_1_1_counter.md#function-show)**() override |
| auto & | **[speed](api/Classes/classbarkeep_1_1_counter.md#function-speed)**(std::optional< double > discount) |
| auto & | **[speed_unit](api/Classes/classbarkeep_1_1_counter.md#function-speed_unit)**(const std::string & msg) |
| auto & | **[message](api/Classes/classbarkeep_1_1_counter.md#function-message)**(const std::string & msg) |
| auto & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**(Duration pd) |
| auto & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**(double pd) |
| auto & | **[no_tty](api/Classes/classbarkeep_1_1_counter.md#function-no_tty)**() |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| size_t | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**(std::ostream & out) |
| virtual size_t | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override |
| void | **[init](api/Classes/classbarkeep_1_1_counter.md#function-init)**(Progress * progress) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(std::ostream & out =std::cout) |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual void | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| void | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**() |
| size_t | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| bool | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**  |


</span>


## Detailed Description

```cpp
template <typename Progress  =size_t>
class barkeep::Counter;
```

## Public Functions Documentation

### function Counter

```cpp
inline Counter(
    Progress * progress,
    std::ostream & out =std::cout
)
```


### function Counter

```cpp
inline Counter(
    const Counter< Progress > & other
)
```


### function Counter

```cpp
inline Counter(
    Counter< Progress > && other
)
```


### function ~Counter

```cpp
inline ~Counter()
```


### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### function show

```cpp
inline virtual void show() override
```


**Reimplements**: [barkeep::AsyncDisplay::show](api/Classes/classbarkeep_1_1_async_display.md#function-show)


### function speed

```cpp
inline auto & speed(
    std::optional< double > discount
)
```


### function speed_unit

```cpp
inline auto & speed_unit(
    const std::string & msg
)
```


### function message

```cpp
inline auto & message(
    const std::string & msg
)
```


### function interval

```cpp
inline auto & interval(
    Duration pd
)
```


### function interval

```cpp
inline auto & interval(
    double pd
)
```


### function no_tty

```cpp
inline auto & no_tty()
```


## Protected Functions Documentation

### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```


### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```


**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### function init

```cpp
inline void init(
    Progress * progress
)
```


### function Counter

```cpp
inline Counter(
    std::ostream & out =std::cout
)
```


-------------------------------

Updated on 2023-11-30 at 22:33:04 -0500