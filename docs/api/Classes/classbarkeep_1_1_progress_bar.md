# barkeep::ProgressBar


 [More...](#detailed-description)

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using ProgressBarStyle | **[Style](api/Classes/classbarkeep_1_1_progress_bar.md#using-style)**  |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)**() override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[total](api/Classes/classbarkeep_1_1_progress_bar.md#function-total)**([ValueType](api/Classes/classbarkeep_1_1_counter.md) tot) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[style](api/Classes/classbarkeep_1_1_progress_bar.md#function-style)**(Style sty) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_progress_bar.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**(Duration pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_progress_bar.md#function-no_tty)**() |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream & out) |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**(std::ostream & out) |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**(std::ostream & out) |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_progress_bar.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(std::ostream & out =std::cout) |


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
template <typenameProgress >
class barkeep::ProgressBar;
```

## Public Types Documentation

### using Style

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


## Public Functions Documentation

### function ProgressBar

```cpp
inline ProgressBar(
    Progress * progress,
    std::ostream & out =std::cout
)
```


### function ProgressBar

```cpp
inline ProgressBar(
    ProgressBar< Progress > && other
)
```


### function ProgressBar

```cpp
inline ProgressBar(
    constProgressBar< Progress > & other
)
```


### function ~ProgressBar

```cpp
inline ~ProgressBar()
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


### function total

```cpp
inline auto & total(
    ValueType tot
)
```


### function style

```cpp
inline auto & style(
    Style sty
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

### function render_progress_bar_

```cpp
inline size_t render_progress_bar_(
    std::ostream & out
)
```


### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```


### function render_percentage_

```cpp
inline size_t render_percentage_(
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


### function ProgressBar

```cpp
inline ProgressBar(
    std::ostream & out =std::cout
)
```


-------------------------------

Updated on 2023-12-01 at 22:33:53 -0500