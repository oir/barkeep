# barkeep::Counter


 [More...](#detailed-description)

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([const](api/Classes/classbarkeep_1_1_counter.md)[Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_counter.md#function-show)**() override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_counter.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_counter.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_counter.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**(Duration pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_counter.md#function-no_tty)**() |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**(std::ostream & out) |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_counter.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(std::ostream & out =std::cout) |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


## Detailed Description

```cpp
template <typenameProgress  =size_t>
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
    constCounter< Progress > & other
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


Start the display. This starts writing the display in the output stream, and computing speed if applicable. 


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


**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


Render a display: animation, progress bar, etc. 


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

Updated on 2023-12-01 at 22:33:53 -0500