## barkeep::Animation


Displays a simple animation with a message. 


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using AnimationStyle | **[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)**  |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([const](api/Classes/classbarkeep_1_1_counter.md)[AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg ={})<br>Constructor.  |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([const](api/Classes/classbarkeep_1_1_counter.md)[Animation](api/Classes/classbarkeep_1_1_animation.md) & other) =default |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) =default |
| | **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**() override<br>Render a display: animation, progress bar, etc.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< [bool](api/Classes/classbarkeep_1_1_counter.md) > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| Duration | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


### Public Types Documentation

#### using Style

```cpp
using barkeep::Animation::Style =  AnimationStyle;
```


### Public Functions Documentation

#### function Animation

```cpp
inline Animation(
    constAnimationConfig & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **cfg** [Animation](api/Classes/classbarkeep_1_1_animation.md) parameters 


#### function Animation

```cpp
Animation(
    constAnimation & other
) =default
```


#### function Animation

```cpp
Animation(
    Animation && 
) =default
```


#### function ~Animation

```cpp
inline ~Animation()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function render_

```cpp
inline virtual void render_() override
```

Render a display: animation, progress bar, etc. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


-------------------------------



## barkeep::AsyncDisplay


Base class to handle all asynchronous displays. 


`#include <barkeep.h>`

Inherited by [barkeep::Animation](api/Classes/classbarkeep_1_1_animation.md), [barkeep::Composite](api/Classes/classbarkeep_1_1_composite.md), [barkeep::Counter< Progress >](api/Classes/classbarkeep_1_1_counter.md), [barkeep::ProgressBar< Progress >](api/Classes/classbarkeep_1_1_progress_bar.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const =0 |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)**() =0<br>Render a display: animation, progress bar, etc.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const =0 |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< [bool](api/Classes/classbarkeep_1_1_counter.md) > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| Duration | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

### Friends

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>

### Public Functions Documentation

#### function AsyncDisplay

```cpp
inline AsyncDisplay(
    std::ostream * out =&std::cout,
    Duration interval =Duration{0.},
    std::string message ="",
    std::string format ="",
    bool no_tty =false
)
```


#### function AsyncDisplay

```cpp
inline AsyncDisplay(
    constAsyncDisplay & other
)
```


#### function AsyncDisplay

```cpp
inline AsyncDisplay(
    AsyncDisplay && other
)
```


#### function ~AsyncDisplay

```cpp
inline virtual ~AsyncDisplay()
```


#### function show

```cpp
inline virtual void show()
```

Start the display. This starts writing the display in the output stream, and computing speed if applicable. 

#### function done

```cpp
inline virtual void done()
```

End the display. 

#### function running

```cpp
inline bool running() const
```


#### function clone

```cpp
virtual std::unique_ptr< AsyncDisplay > clone() const =0
```


**Reimplemented by**: [barkeep::Animation::clone](api/Classes/classbarkeep_1_1_animation.md#function-clone), [barkeep::Composite::clone](api/Classes/classbarkeep_1_1_composite.md#function-clone), [barkeep::Counter::clone](api/Classes/classbarkeep_1_1_counter.md#function-clone), [barkeep::ProgressBar::clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)


### Protected Functions Documentation

#### function render_

```cpp
virtual void render_() =0
```

Render a display: animation, progress bar, etc. 

**Reimplemented by**: [barkeep::Animation::render_](api/Classes/classbarkeep_1_1_animation.md#function-render_), [barkeep::Composite::render_](api/Classes/classbarkeep_1_1_composite.md#function-render_), [barkeep::Counter::render_](api/Classes/classbarkeep_1_1_counter.md#function-render_), [barkeep::ProgressBar::render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)


#### function default_interval_

```cpp
virtual Duration default_interval_() const =0
```


**Reimplemented by**: [barkeep::Animation::default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_), [barkeep::Composite::default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_), [barkeep::Counter::default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_), [barkeep::ProgressBar::default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)


#### function display_

```cpp
inline void display_()
```

Display everything (message, maybe with animation, progress bar, etc). 

#### function render_message_

```cpp
inline void render_message_() const
```

Display the message to output stream. 

#### function start

```cpp
inline virtual void start()
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplemented by**: [barkeep::Composite::start](api/Classes/classbarkeep_1_1_composite.md#function-start), [barkeep::Counter::start](api/Classes/classbarkeep_1_1_counter.md#function-start), [barkeep::ProgressBar::start](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)


#### function join

```cpp
inline virtual void join()
```

Join the display thread. Protected because python bindings need to override to handle GIL. 

#### function ensure_not_running

```cpp
inline void ensure_not_running() const
```


### Protected Attributes Documentation

#### variable out_

```cpp
std::ostream * out_;
```


#### variable displayer_

```cpp
std::unique_ptr< std::thread > displayer_;
```


#### variable completion_

```cpp
std::condition_variable completion_;
```


#### variable completion_m_

```cpp
std::mutex completion_m_;
```


#### variable complete_

```cpp
std::atomic< bool > complete_ = false;
```


#### variable interval_

```cpp
Duration interval_ {0.0};
```


#### variable message_

```cpp
std::string message_;
```


#### variable format_

```cpp
std::string format_;
```


#### variable no_tty_

```cpp
bool no_tty_ = false;
```


### Friends

#### friend Composite

```cpp
friend class Composite(
    Composite 
);
```


-------------------------------



## barkeep::Composite


Creates a composite display out of two display that shows them side by side. For instance, you can combine two [Counter](api/Classes/classbarkeep_1_1_counter.md) objects to monitor two variables. 


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > left, std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > right) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([const](api/Classes/classbarkeep_1_1_counter.md)[Composite](api/Classes/classbarkeep_1_1_composite.md) & other)<br>Copy constructor clones child displays.  |
| | **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**() override<br>Render a display: animation, progress bar, etc.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_composite.md#function-start)**() override<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[left_](api/Classes/classbarkeep_1_1_composite.md#variable-left_)**  |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[right_](api/Classes/classbarkeep_1_1_composite.md#variable-right_)**  |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< [bool](api/Classes/classbarkeep_1_1_counter.md) > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| Duration | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>


### Public Functions Documentation

#### function Composite

```cpp
inline Composite(
    std::unique_ptr< AsyncDisplay > left,
    std::unique_ptr< AsyncDisplay > right
)
```


#### function Composite

```cpp
inline Composite(
    constComposite & other
)
```

Copy constructor clones child displays. 

#### function ~Composite

```cpp
inline ~Composite()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function render_

```cpp
inline virtual void render_() override
```

Render a display: animation, progress bar, etc. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function start

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [barkeep::AsyncDisplay::start](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### Protected Attributes Documentation

#### variable left_

```cpp
std::unique_ptr< AsyncDisplay > left_;
```


#### variable right_

```cpp
std::unique_ptr< AsyncDisplay > right_;
```


-------------------------------



## barkeep::Counter


Monitors and displays a single numeric variable.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, [const](api/Classes/classbarkeep_1_1_counter.md)[CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md) & cfg ={})<br>Constructor.  |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([const](api/Classes/classbarkeep_1_1_counter.md)[Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**()<br>Write the value of progress to the output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**() override<br>Write the value of progress with the message to the output stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override<br>Default interval in which the display is refreshed, if interval() is not invoked.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_counter.md#function-start)**() override<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [Progress](api/Classes/classbarkeep_1_1_counter.md) * | **[progress_](api/Classes/classbarkeep_1_1_counter.md#variable-progress_)**  |
| std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > > | **[speedom_](api/Classes/classbarkeep_1_1_counter.md#variable-speedom_)**  |
| std::string | **[speed_unit_](api/Classes/classbarkeep_1_1_counter.md#variable-speed_unit_)**  |
| std::stringstream | **[ss_](api/Classes/classbarkeep_1_1_counter.md#variable-ss_)**  |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< [bool](api/Classes/classbarkeep_1_1_counter.md) > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| Duration | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


### Detailed Description

```cpp
template <typenameProgress  =size_t>
class barkeep::Counter;
```

Monitors and displays a single numeric variable. 
### Public Functions Documentation

#### function Counter

```cpp
inline Counter(
    Progress * progress,
    constCounterConfig & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored and displayed 
  * **cfg** [Counter](api/Classes/classbarkeep_1_1_counter.md) parameters 


#### function Counter

```cpp
inline Counter(
    constCounter< Progress > & other
)
```


#### function Counter

```cpp
inline Counter(
    Counter< Progress > && other
)
```


#### function ~Counter

```cpp
inline ~Counter()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function render_counts_

```cpp
inline void render_counts_()
```

Write the value of progress to the output stream. 

#### function render_

```cpp
inline virtual void render_() override
```

Write the value of progress with the message to the output stream. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```

Default interval in which the display is refreshed, if interval() is not invoked. 

**Return**: default interval 

**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function start

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [barkeep::AsyncDisplay::start](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### Protected Attributes Documentation

#### variable progress_

```cpp
Progress * progress_ = nullptr;
```


#### variable speedom_

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


#### variable speed_unit_

```cpp
std::string speed_unit_ = "it/s";
```


#### variable ss_

```cpp
std::stringstream ss_;
```


-------------------------------



## barkeep::IterableBar


A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md)**  |


</span>

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using std::atomic< [size_t](api/Classes/classbarkeep_1_1_counter.md) > | **[ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype)**  |
| using value_t< ProgressType > | **[ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype)**  |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md#function-iterablebar)**([Container](api/Classes/classbarkeep_1_1_counter.md) & container, [const](api/Classes/classbarkeep_1_1_counter.md)[IterableBarConfig](api/Classes/structbarkeep_1_1_iterable_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_counter.md) > & cfg ={}) |
| [auto](api/Classes/classbarkeep_1_1_counter.md) | **[begin](api/Classes/classbarkeep_1_1_iterable_bar.md#function-begin)**() |
| [auto](api/Classes/classbarkeep_1_1_counter.md) | **[end](api/Classes/classbarkeep_1_1_iterable_bar.md#function-end)**() |


</span>

### Detailed Description

```cpp
template <typenameContainer >
class barkeep::IterableBar;
```

A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop. 
### Public Types Documentation

#### using ProgressType

```cpp
using barkeep::IterableBar< Container >::ProgressType =  std::atomic<size_t>;
```


#### using ValueType

```cpp
using barkeep::IterableBar< Container >::ValueType =  value_t<ProgressType>;
```


### Public Functions Documentation

#### function IterableBar

```cpp
inline IterableBar(
    Container & container,
    constIterableBarConfig< ValueType > & cfg ={}
)
```


#### function begin

```cpp
inline auto begin()
```


#### function end

```cpp
inline auto end()
```


-------------------------------



## barkeep::IterableBar::Iterator




### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-iterator)**([typename](api/Classes/classbarkeep_1_1_counter.md) Container::iterator it, ProgressType & idx) |
| [Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & | **[operator++](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator++)**() |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[operator!=](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator!=)**([const](api/Classes/classbarkeep_1_1_counter.md)[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & other) const |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[operator*](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator*)**() |


</span>

### Public Functions Documentation

#### function Iterator

```cpp
inline Iterator(
    typename Container::iterator it,
    ProgressType & idx
)
```


#### function operator++

```cpp
inline Iterator & operator++()
```


#### function operator!=

```cpp
inline bool operator!=(
    constIterator & other
) const
```


#### function operator*

```cpp
inline auto & operator*()
```


-------------------------------



## barkeep::ProgressBar


Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using ProgressBarStyle | **[Style](api/Classes/classbarkeep_1_1_progress_bar.md#using-style)**  |


</span>

### Protected Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using value_t< [Progress](api/Classes/classbarkeep_1_1_counter.md) > | **[ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype)**  |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, [const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_counter.md) > & cfg ={})<br>Constructor.  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other)<br>move constructor  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other)<br>copy constructor  |
| | **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream * out =[nullptr](api/Classes/classbarkeep_1_1_counter.md))<br>Compute the shape of the progress bar based on progress and write to output stream.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**()<br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**()<br>Write the percent completed to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**() override<br>Run all of the individual render methods to write everything to stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)**() override<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [Progress](api/Classes/classbarkeep_1_1_counter.md) * | **[progress_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-progress_)**  |
| std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > > | **[speedom_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-speedom_)**  |
| std::string | **[speed_unit_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-speed_unit_)**  |
| [ValueType](api/Classes/classbarkeep_1_1_counter.md) | **[total_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-total_)**  |
| [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) | **[bar_parts_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-bar_parts_)**  |
| [constexpr](api/Classes/classbarkeep_1_1_counter.md)[size_t](api/Classes/classbarkeep_1_1_counter.md) | **[width_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-width_)**  |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< [bool](api/Classes/classbarkeep_1_1_counter.md) > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| Duration | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


### Detailed Description

```cpp
template <typenameProgress >
class barkeep::ProgressBar;
```

Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
### Public Types Documentation

#### using Style

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


### Protected Types Documentation

#### using ValueType

```cpp
using barkeep::ProgressBar< Progress >::ValueType =  value_t<Progress>;
```


### Public Functions Documentation

#### function ProgressBar

```cpp
inline ProgressBar(
    Progress * progress,
    constProgressBarConfig< ValueType > & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored to measure completion 
  * **cfg** [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md) parameters 


#### function ProgressBar

```cpp
inline ProgressBar(
    ProgressBar< Progress > && other
)
```

move constructor 

#### function ProgressBar

```cpp
inline ProgressBar(
    constProgressBar< Progress > & other
)
```

copy constructor 

#### function ~ProgressBar

```cpp
inline ~ProgressBar()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function render_progress_bar_

```cpp
inline void render_progress_bar_(
    std::ostream * out =nullptr
)
```

Compute the shape of the progress bar based on progress and write to output stream. 

#### function render_counts_

```cpp
inline void render_counts_()
```

Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total. 

#### function render_percentage_

```cpp
inline void render_percentage_()
```

Write the percent completed to output stream. 

#### function render_

```cpp
inline virtual void render_() override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function start

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [barkeep::AsyncDisplay::start](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### Protected Attributes Documentation

#### variable progress_

```cpp
Progress * progress_;
```


#### variable speedom_

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


#### variable speed_unit_

```cpp
std::string speed_unit_ = "it/s";
```


#### variable total_

```cpp
ValueType total_ {100};
```


#### variable bar_parts_

```cpp
BarParts bar_parts_;
```


#### variable width_

```cpp
static constexprsize_t width_ = 30;
```


-------------------------------



## barkeep::Speedometer


Helper class to measure and display speed of progress.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [double](api/Classes/classbarkeep_1_1_counter.md) | **[speed](api/Classes/classbarkeep_1_1_speedometer.md#function-speed)**() |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream * out, [const](api/Classes/classbarkeep_1_1_counter.md) std::string & speed_unit)<br>Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_speedometer.md#function-start)**()<br>Start computing the speed based on the amount of change in progress.  |
| | **[Speedometer](api/Classes/classbarkeep_1_1_speedometer.md#function-speedometer)**([Progress](api/Classes/classbarkeep_1_1_counter.md) & progress, [double](api/Classes/classbarkeep_1_1_counter.md) discount)<br>Constructor.  |


</span>

### Detailed Description

```cpp
template <typenameProgress >
class barkeep::Speedometer;
```

Helper class to measure and display speed of progress. 
### Public Functions Documentation

#### function speed

```cpp
inline double speed()
```


#### function render_speed

```cpp
inline void render_speed(
    std::ostream * out,
    const std::string & speed_unit
)
```

Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed. 

#### function start

```cpp
inline void start()
```

Start computing the speed based on the amount of change in progress. 

#### function Speedometer

```cpp
inline Speedometer(
    Progress & progress,
    double discount
)
```

Constructor. 

**Parameters**: 

  * **progress** Reference to numeric to measure the change of. 
  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. 


-------------------------------



## barkeep::AnimationConfig


[Animation](api/Classes/classbarkeep_1_1_animation.md) parameters. 


`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_animation_config.md#variable-out)** <br>output stream  |
| std::string | **[message](api/Classes/structbarkeep_1_1_animation_config.md#variable-message)** <br>message to display before the animation style as AnimationStyle or custom animation as a list of strings  |
| std::variant< AnimationStyle, Strings > | **[style](api/Classes/structbarkeep_1_1_animation_config.md#variable-style)**  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_animation_config.md#variable-interval)** <br>interval in which the animation is refreshed  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_animation_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/structbarkeep_1_1_animation_config.md#variable-show)** <br>show the animation immediately after construction  |


</span>

### Public Attributes Documentation

#### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable message

```cpp
std::string message = "";
```

message to display before the animation style as AnimationStyle or custom animation as a list of strings 

#### variable style

```cpp
std::variant< AnimationStyle, Strings > style = Ellipsis;
```


#### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the animation is refreshed 

#### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

#### variable show

```cpp
bool show = true;
```

show the animation immediately after construction 

-------------------------------



## barkeep::AtomicTraits


Trait class to extract underlying value type from numerics and std::atomics of numerics.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [T](api/Classes/classbarkeep_1_1_counter.md) | **[value_type](api/Classes/structbarkeep_1_1_atomic_traits.md#using-value_type)**  |


</span>

### Detailed Description

```cpp
template <typenameT >
struct barkeep::AtomicTraits;
```

Trait class to extract underlying value type from numerics and std::atomics of numerics. 
### Public Types Documentation

#### using value_type

```cpp
using barkeep::AtomicTraits< T >::value_type =  T;
```


-------------------------------



## barkeep::AtomicTraits< std::atomic< T > >


 [More...](#detailed-description)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using [T](api/Classes/classbarkeep_1_1_counter.md) | **[value_type](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md#using-value_type)**  |


</span>

### Detailed Description

```cpp
template <typenameT >
struct barkeep::AtomicTraits< std::atomic< T > >;
```

### Public Types Documentation

#### using value_type

```cpp
using barkeep::AtomicTraits< std::atomic< T > >::value_type =  T;
```


-------------------------------



## barkeep::BarParts




### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::string | **[left](api/Classes/structbarkeep_1_1_bar_parts.md#variable-left)**  |
| std::string | **[right](api/Classes/structbarkeep_1_1_bar_parts.md#variable-right)**  |
| Strings | **[fill](api/Classes/structbarkeep_1_1_bar_parts.md#variable-fill)**  |
| Strings | **[empty](api/Classes/structbarkeep_1_1_bar_parts.md#variable-empty)**  |
| std::string | **[incomplete_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-incomplete_left_modifier)**  |
| std::string | **[complete_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-complete_left_modifier)**  |
| std::string | **[middle_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-middle_modifier)**  |
| std::string | **[right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-right_modifier)**  |
| std::string | **[percent_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-percent_left_modifier)**  |
| std::string | **[percent_right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-percent_right_modifier)**  |
| std::string | **[value_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-value_left_modifier)**  |
| std::string | **[value_right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-value_right_modifier)**  |
| std::string | **[speed_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-speed_left_modifier)**  |
| std::string | **[speed_right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-speed_right_modifier)**  |


</span>

### Public Attributes Documentation

#### variable left

```cpp
std::string left;
```


#### variable right

```cpp
std::string right;
```


#### variable fill

```cpp
Strings fill;
```


#### variable empty

```cpp
Strings empty;
```


#### variable incomplete_left_modifier

```cpp
std::string incomplete_left_modifier = "";
```


#### variable complete_left_modifier

```cpp
std::string complete_left_modifier = "";
```


#### variable middle_modifier

```cpp
std::string middle_modifier = "";
```


#### variable right_modifier

```cpp
std::string right_modifier = "";
```


#### variable percent_left_modifier

```cpp
std::string percent_left_modifier = "";
```


#### variable percent_right_modifier

```cpp
std::string percent_right_modifier = "";
```


#### variable value_left_modifier

```cpp
std::string value_left_modifier = "";
```


#### variable value_right_modifier

```cpp
std::string value_right_modifier = "";
```


#### variable speed_left_modifier

```cpp
std::string speed_left_modifier = "";
```


#### variable speed_right_modifier

```cpp
std::string speed_right_modifier = "";
```


-------------------------------



## barkeep::CounterConfig


[Counter](api/Classes/classbarkeep_1_1_counter.md) parameters. 


`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_counter_config.md#variable-out)** <br>output stream  |
| std::string | **[format](api/Classes/structbarkeep_1_1_counter_config.md#variable-format)** <br>format string to format entire counter  |
| std::string | **[message](api/Classes/structbarkeep_1_1_counter_config.md#variable-message)** <br>message to display with the counter  |
| std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > | **[speed](api/Classes/structbarkeep_1_1_counter_config.md#variable-speed)** <br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| std::string | **[speed_unit](api/Classes/structbarkeep_1_1_counter_config.md#variable-speed_unit)** <br>unit of speed text next to speed interval in which the counter is refreshed  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_counter_config.md#variable-interval)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_counter_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/structbarkeep_1_1_counter_config.md#variable-show)** <br>show the counter immediately after construction  |


</span>

### Public Attributes Documentation

#### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable format

```cpp
std::string format = "";
```

format string to format entire counter 

#### variable message

```cpp
std::string message = "";
```

message to display with the counter 

#### variable speed

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

#### variable speed_unit

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed interval in which the counter is refreshed 

#### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```


#### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

#### variable show

```cpp
bool show = true;
```

show the counter immediately after construction 

-------------------------------



## barkeep::IterableBarConfig


 [More...](#detailed-description)

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-out)** <br>output stream  |
| std::string | **[format](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-format)** <br>format string for the entire progress bar  |
| std::string | **[message](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-message)** <br>message to display with the bar  |
| std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > | **[speed](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed)** <br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| std::string | **[speed_unit](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed_unit)** <br>unit of speed text next to speed  |
| ProgressBarStyle | **[style](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-style)** <br>style of progress bar interval in which the progress bar is refreshed  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-interval)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |


</span>

### Detailed Description

```cpp
template <typename ValueType >
struct barkeep::IterableBarConfig;
```

### Public Attributes Documentation

#### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable format

```cpp
std::string format = "";
```

format string for the entire progress bar 

#### variable message

```cpp
std::string message = "";
```

message to display with the bar 

#### variable speed

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

#### variable speed_unit

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed 

#### variable style

```cpp
ProgressBarStyle style = Blocks;
```

style of progress bar interval in which the progress bar is refreshed 

#### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```


#### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

-------------------------------



## barkeep::ProgressBarConfig


 [More...](#detailed-description)

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-out)** <br>output stream  |
| ValueType | **[total](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-total)** <br>total amount of work for a full bar  |
| std::string | **[format](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-format)** <br>format string for the entire progress bar  |
| std::string | **[message](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-message)** <br>message to display with the bar  |
| std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > | **[speed](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-speed)** <br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| std::string | **[speed_unit](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-speed_unit)** <br>unit of speed text next to speed progress bar style, or custom style as [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) |
| std::variant< ProgressBarStyle, [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) > | **[style](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-style)**  |
| std::variant< Duration, [double](api/Classes/classbarkeep_1_1_counter.md) > | **[interval](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-interval)** <br>interval in which the progress bar is refreshed  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-show)** <br>show the progress bar immediately after construction  |


</span>

### Detailed Description

```cpp
template <typename ValueType >
struct barkeep::ProgressBarConfig;
```

### Public Attributes Documentation

#### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable total

```cpp
ValueType total = 100;
```

total amount of work for a full bar 

#### variable format

```cpp
std::string format = "";
```

format string for the entire progress bar 

#### variable message

```cpp
std::string message = "";
```

message to display with the bar 

#### variable speed

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

#### variable speed_unit

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed progress bar style, or custom style as [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md)

#### variable style

```cpp
std::variant< ProgressBarStyle, BarParts > style = Blocks;
```


#### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the progress bar is refreshed 

#### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

#### variable show

```cpp
bool show = true;
```

show the progress bar immediately after construction 

-------------------------------

Updated on 2024-03-28 at 21:56:22 -0400