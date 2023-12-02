# barkeep::AsyncDisplay


Base class to handle all asynchronous displays. 


`#include <barkeep.h>`

Inherited by [barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md), [barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md), [barkeep::Counter< Progress >](api/Classes/classbarkeep_1_1_counter.md), [barkeep::ProgressBar< Progress >](api/Classes/classbarkeep_1_1_progress_bar.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const =0 |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)**(std::ostream & out) =0<br>Render a display: animation, progress bar, etc.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const =0 |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const<br>Display the message to output stream.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd)<br>Set the interval in which the display is refreshed. This is also the interval in which speed is measured if applicable.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_async_display.md#function-interval) to accept a double argument.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/classbarkeep_1_1_async_display.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

## Friends

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


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
    constAsyncDisplay & other
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

Start the display. This starts writing the display in the output stream, and computing speed if applicable. 

**Reimplemented by**: [barkeep::Counter::show](api/Classes/classbarkeep_1_1_counter.md#function-show), [barkeep::ProgressBar::show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)


### function done

```cpp
inline virtual void done()
```

End the display. This adds a newline to the output stream and stops writing. 

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

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

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

Display everything (message, maybe with animation, progress bar, etc). 

### function render_message_

```cpp
inline size_t render_message_(
    std::ostream & out
) const
```

Display the message to output stream. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered message 

### function message

```cpp
inline void message(
    const std::string & msg
)
```

Set message to be displayed. 

**Parameters**: 

  * **msg** message to be displayed 


### function interval

```cpp
inline void interval(
    Duration pd
)
```

Set the interval in which the display is refreshed. This is also the interval in which speed is measured if applicable. 

**Parameters**: 

  * **pd** interval as a Duration 


### function interval

```cpp
inline void interval(
    double pd
)
```

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_async_display.md#function-interval) to accept a double argument. 

**Parameters**: 

  * **pd** interval as a double 


### function no_tty

```cpp
inline void no_tty()
```

Enable no-tty mode. 

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

Updated on 2023-12-02 at 13:34:20 -0500