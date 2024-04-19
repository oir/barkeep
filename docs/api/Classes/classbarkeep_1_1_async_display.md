# barkeep::AsyncDisplay


Base class to handle all asynchronous displays. 


`#include <barkeep.h>`

Inherited by [barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md), [barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md), [barkeep::Counter< Progress >](api/Classes/classbarkeep_1_1_counter.md), [barkeep::ProgressBar< Progress >](api/Classes/classbarkeep_1_1_progress_bar.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval =[Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.}, std::string message ="", std::string format ="", bool no_tty =false) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual void | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual void | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| bool | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const =0 |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual void | **[render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)**() =0<br>Render a display: animation, progress bar, etc.  |
| virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) | **[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const =0 |
| void | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| void | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual void | **[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| virtual void | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| void | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< bool > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| [Duration](api/Namespaces/namespacebarkeep.md#using-duration) | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
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
    std::ostream * out =&std::cout,
    Duration interval =Duration{0.},
    std::string message ="",
    std::string format ="",
    bool no_tty =false
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

Start the display. This starts writing the display in the output stream, and computing speed if applicable. 

### function done

```cpp
inline virtual void done()
```

End the display. 

### function running

```cpp
inline bool running() const
```


### function clone

```cpp
virtual std::unique_ptr< AsyncDisplay > clone() const =0
```


**Reimplemented by**: [barkeep::Animation::clone](api/Classes/classbarkeep_1_1_animation.md#function-clone), [barkeep::Composite::clone](api/Classes/classbarkeep_1_1_composite.md#function-clone), [barkeep::Counter::clone](api/Classes/classbarkeep_1_1_counter.md#function-clone), [barkeep::ProgressBar::clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)


## Protected Functions Documentation

### function render_

```cpp
virtual void render_() =0
```

Render a display: animation, progress bar, etc. 

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
inline void render_message_() const
```

Display the message to output stream. 

### function start

```cpp
inline virtual void start()
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplemented by**: [barkeep::Composite::start](api/Classes/classbarkeep_1_1_composite.md#function-start), [barkeep::Counter::start](api/Classes/classbarkeep_1_1_counter.md#function-start), [barkeep::ProgressBar::start](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)


### function join

```cpp
inline virtual void join()
```

Join the display thread. Protected because python bindings need to override to handle GIL. 

### function ensure_not_running

```cpp
inline void ensure_not_running() const
```


## Protected Attributes Documentation

### variable out_

```cpp
std::ostream * out_;
```


### variable displayer_

```cpp
std::unique_ptr< std::thread > displayer_;
```


### variable completion_

```cpp
std::condition_variable completion_;
```


### variable completion_m_

```cpp
std::mutex completion_m_;
```


### variable complete_

```cpp
std::atomic< bool > complete_ = false;
```


### variable interval_

```cpp
Duration interval_ {0.0};
```


### variable message_

```cpp
std::string message_;
```


### variable format_

```cpp
std::string format_;
```


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

Updated on 2024-03-28 at 22:58:08 -0400