# barkeep::AsyncDisplay




Inherited by [barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md), [barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md), [barkeep::Counter< Progress >](api/Classes/classbarkeep_1_1_counter.md), [barkeep::ProgressBar< Progress >](api/Classes/classbarkeep_1_1_progress_bar.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual void | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual void | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const =0 |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual size_t | **[render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)**(std::ostream & out) =0 |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const =0 |
| void | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**() |
| size_t | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |
| void | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**(const std::string & msg) |
| void | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd) |
| void | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(double pd) |
| void | **[no_tty](api/Classes/classbarkeep_1_1_async_display.md#function-no_tty)**() |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| bool | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

## Friends

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**  |


</span>

## Public Functions Documentation

### function AsyncDisplay

```cpp
inline AsyncDisplay(
    std::ostream & out =std::cout
)
```


### function AsyncDisplay

```cpp
inline AsyncDisplay(
    const AsyncDisplay & other
)
```


### function AsyncDisplay

```cpp
inline AsyncDisplay(
    AsyncDisplay && other
)
```


### function ~AsyncDisplay

```cpp
inline virtual ~AsyncDisplay()
```


### function show

```cpp
inline virtual void show()
```


**Reimplemented by**: [barkeep::Counter::show](api/Classes/classbarkeep_1_1_counter.md#function-show), [barkeep::ProgressBar::show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)


### function done

```cpp
inline virtual void done()
```


### function clone

```cpp
virtual std::unique_ptr< AsyncDisplay > clone() const =0
```


**Reimplemented by**: [barkeep::Animation::clone](api/Classes/classbarkeep_1_1_animation.md#function-clone), [barkeep::Composite::clone](api/Classes/classbarkeep_1_1_composite.md#function-clone), [barkeep::Counter::clone](api/Classes/classbarkeep_1_1_counter.md#function-clone), [barkeep::ProgressBar::clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)


## Protected Functions Documentation

### function render_

```cpp
virtual size_t render_(
    std::ostream & out
) =0
```


**Reimplemented by**: [barkeep::Animation::render_](api/Classes/classbarkeep_1_1_animation.md#function-render_), [barkeep::Composite::render_](api/Classes/classbarkeep_1_1_composite.md#function-render_), [barkeep::Counter::render_](api/Classes/classbarkeep_1_1_counter.md#function-render_), [barkeep::ProgressBar::render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)


### function default_interval_

```cpp
virtual Duration default_interval_() const =0
```


**Reimplemented by**: [barkeep::Animation::default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_), [barkeep::Composite::default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_), [barkeep::Counter::default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_), [barkeep::ProgressBar::default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)


### function display_

```cpp
inline void display_()
```


### function render_message_

```cpp
inline size_t render_message_(
    std::ostream & out
) const
```


### function message

```cpp
inline void message(
    const std::string & msg
)
```


### function interval

```cpp
inline void interval(
    Duration pd
)
```


### function interval

```cpp
inline void interval(
    double pd
)
```


### function no_tty

```cpp
inline void no_tty()
```


## Protected Attributes Documentation

### variable no_tty_

```cpp
bool no_tty_ = false;
```


## Friends

### friend Composite

```cpp
friend class Composite(
    Composite 
);
```


-------------------------------

Updated on 2023-11-30 at 22:33:04 -0500