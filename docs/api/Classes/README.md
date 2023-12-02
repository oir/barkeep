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
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(std::ostream & out =std::cout)<br>Constructor.  |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([const](api/Classes/classbarkeep_1_1_counter.md)[Animation](api/Classes/classbarkeep_1_1_animation.md) & other) =default |
| | **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) =default |
| | **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[style](api/Classes/classbarkeep_1_1_animation.md#function-style)**(Style sty)<br>Set animation style using one of AnimationStyle.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_animation.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_animation.md#function-interval)**(Duration pd)<br>Set interval in which the animation is refreshed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_animation.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_animation.md#function-interval) to accept a double argument.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_animation.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**(std::ostream & out) override<br>Render a display: animation, progress bar, etc.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const<br>Display the message to output stream.  |


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


### Public Types Documentation

#### using Style

```cpp
using barkeep::Animation::Style =  AnimationStyle;
```


### Public Functions Documentation

#### function Animation

```cpp
inline Animation(
    std::ostream & out =std::cout
)
```

Constructor. 

**Parameters**: 

  * **out** output stream to write to 


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


#### function style

```cpp
inline auto & style(
    Style sty
)
```

Set animation style using one of AnimationStyle. 

**Parameters**: 

  * **sty** 


**Return**: reference to self 

#### function message

```cpp
inline auto & message(
    const std::string & msg
)
```

Set message to be displayed. 

**Parameters**: 

  * **msg** 


**Return**: reference to self 

#### function interval

```cpp
inline auto & interval(
    Duration pd
)
```

Set interval in which the animation is refreshed. 

**Parameters**: 

  * **pd** 


**Return**: reference to self 

#### function interval

```cpp
inline auto & interval(
    double pd
)
```

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_animation.md#function-interval) to accept a double argument. 

**Parameters**: 

  * **pd** 


**Return**: reference to self 

#### function no_tty

```cpp
inline auto & no_tty()
```

Enable no-tty mode. 

**Return**: reference to self 

### Protected Functions Documentation

#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

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
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const =0 |


</span>

### Protected Functions

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

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
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
    std::ostream & out =std::cout
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

**Reimplemented by**: [barkeep::Counter::show](api/Classes/classbarkeep_1_1_counter.md#function-show), [barkeep::ProgressBar::show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)


#### function done

```cpp
inline virtual void done()
```

End the display. This adds a newline to the output stream and stops writing. 

#### function clone

```cpp
virtual std::unique_ptr< AsyncDisplay > clone() const =0
```


**Reimplemented by**: [barkeep::Animation::clone](api/Classes/classbarkeep_1_1_animation.md#function-clone), [barkeep::Composite::clone](api/Classes/classbarkeep_1_1_composite.md#function-clone), [barkeep::Counter::clone](api/Classes/classbarkeep_1_1_counter.md#function-clone), [barkeep::ProgressBar::clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)


### Protected Functions Documentation

#### function render_

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
inline size_t render_message_(
    std::ostream & out
) const
```

Display the message to output stream. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered message 

#### function message

```cpp
inline void message(
    const std::string & msg
)
```

Set message to be displayed. 

**Parameters**: 

  * **msg** message to be displayed 


#### function interval

```cpp
inline void interval(
    Duration pd
)
```

Set the interval in which the display is refreshed. This is also the interval in which speed is measured if applicable. 

**Parameters**: 

  * **pd** interval as a Duration 


#### function interval

```cpp
inline void interval(
    double pd
)
```

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_async_display.md#function-interval) to accept a double argument. 

**Parameters**: 

  * **pd** interval as a double 


#### function no_tty

```cpp
inline void no_tty()
```

Enable no-tty mode. 

### Protected Attributes Documentation

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
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) && other) =default |
| | **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_composite.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**(std::ostream & out) override<br>Render a display: animation, progress bar, etc.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override |


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
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const<br>Display the message to output stream.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd)<br>Set the interval in which the display is refreshed. This is also the interval in which speed is measured if applicable.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_async_display.md#function-interval) to accept a double argument.  |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
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

#### function Composite

```cpp
Composite(
    Composite && other
) =default
```


#### function ~Composite

```cpp
inline ~Composite()
```


#### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


#### function no_tty

```cpp
inline auto & no_tty()
```

Enable no-tty mode. 

**Return**: reference to self 

### Protected Functions Documentation

#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered display 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


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
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout)<br>Constructor.  |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([const](api/Classes/classbarkeep_1_1_counter.md)[Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_counter.md#function-show)**() override<br>Start displaying the counter.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_counter.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount)<br>Set how to compute speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_counter.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set unit of speed text next to speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_counter.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**(Duration pd)<br>Set interval in which the display is refreshed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_counter.md#function-interval) to accept a double argument.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_counter.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**(std::ostream & out)<br>Write the value of progress to the output stream.  |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**(std::ostream & out) override<br>Write the value of progress with the message to the output stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override<br>Default interval in which the display is refreshed, if [interval()](api/Classes/classbarkeep_1_1_counter.md#function-interval) is not invoked.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_counter.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(std::ostream & out =std::cout) |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const<br>Display the message to output stream.  |


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
    std::ostream & out =std::cout
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored and displayed 
  * **out** Output stream to write to 


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


#### function show

```cpp
inline virtual void show() override
```

Start displaying the counter. 

**Reimplements**: [barkeep::AsyncDisplay::show](api/Classes/classbarkeep_1_1_async_display.md#function-show)


#### function speed

```cpp
inline auto & speed(
    std::optional< double > discount
)
```

Set how to compute speed. 

**Parameters**: 

  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. If discount is `std::nullopt`, speed is not computed. 


**Return**: reference to self 

#### function speed_unit

```cpp
inline auto & speed_unit(
    const std::string & msg
)
```

Set unit of speed text next to speed. 

**Parameters**: 

  * **msg** unit of speed 


**Return**: reference to self 

#### function message

```cpp
inline auto & message(
    const std::string & msg
)
```

Set message to be displayed. 

**Parameters**: 

  * **msg** Message 


**Return**: reference to self 

#### function interval

```cpp
inline auto & interval(
    Duration pd
)
```

Set interval in which the display is refreshed. 

**Parameters**: 

  * **pd** interval as a Duration 


**Return**: reference to self 

#### function interval

```cpp
inline auto & interval(
    double pd
)
```

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_counter.md#function-interval) to accept a double argument. 

**Parameters**: 

  * **pd** interval as a double 


**Return**: reference to self 

#### function no_tty

```cpp
inline auto & no_tty()
```

Enable no-tty mode. 

**Return**: reference to self 

### Protected Functions Documentation

#### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```

Write the value of progress to the output stream. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered value 

#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```

Write the value of progress with the message to the output stream. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered string 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```

Default interval in which the display is refreshed, if [interval()](api/Classes/classbarkeep_1_1_counter.md#function-interval) is not invoked. 

**Return**: default interval 

**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function init

```cpp
inline void init(
    Progress * progress
)
```


#### function Counter

```cpp
inline Counter(
    std::ostream & out =std::cout
)
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

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout)<br>Constructor.  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other)<br>move constructor  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other)<br>copy constructor  |
| | **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)**() override<br>Start displaying the bar.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount)<br>Set how to compute speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set unit of speed text next to speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[total](api/Classes/classbarkeep_1_1_progress_bar.md#function-total)**([ValueType](api/Classes/classbarkeep_1_1_counter.md) tot)<br>Set total amount of work to be done, for the progress bar to be full.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[style](api/Classes/classbarkeep_1_1_progress_bar.md#function-style)**(Style sty)<br>Set progress bar style.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_progress_bar.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**(Duration pd)<br>Set interval in which the display is refreshed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval) to accept a double argument.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_progress_bar.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream & out)<br>Compute the shape of the progress bar based on progress and write to output stream.  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**(std::ostream & out)<br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**(std::ostream & out)<br>Write the percent completed to output stream.  |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**(std::ostream & out) override<br>Run all of the individual render methods to write everything to stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_progress_bar.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(std::ostream & out =std::cout) |


</span>

### Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const<br>Display the message to output stream.  |


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


### Public Functions Documentation

#### function ProgressBar

```cpp
inline ProgressBar(
    Progress * progress,
    std::ostream & out =std::cout
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored to measure completion 
  * **out** Output stream to write to 


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


#### function show

```cpp
inline virtual void show() override
```

Start displaying the bar. 

**Reimplements**: [barkeep::AsyncDisplay::show](api/Classes/classbarkeep_1_1_async_display.md#function-show)


#### function speed

```cpp
inline auto & speed(
    std::optional< double > discount
)
```

Set how to compute speed. 

**Parameters**: 

  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. If discount is `std::nullopt`, speed is not computed. 


**Return**: reference to self 

#### function speed_unit

```cpp
inline auto & speed_unit(
    const std::string & msg
)
```

Set unit of speed text next to speed. 

**Parameters**: 

  * **msg** unit of speed 


**Return**: reference to self 

#### function total

```cpp
inline auto & total(
    ValueType tot
)
```

Set total amount of work to be done, for the progress bar to be full. 

**Parameters**: 

  * **tot** total amount of work 


**Return**: reference to self 

#### function style

```cpp
inline auto & style(
    Style sty
)
```

Set progress bar style. 

**Parameters**: 

  * **sty** Style 


**Return**: reference to self 

#### function message

```cpp
inline auto & message(
    const std::string & msg
)
```

Set message to be displayed. 

**Parameters**: 

  * **msg** Message 


**Return**: reference to self 

#### function interval

```cpp
inline auto & interval(
    Duration pd
)
```

Set interval in which the display is refreshed. 

**Parameters**: 

  * **pd** interval as a Duration 


**Return**: reference to self 

#### function interval

```cpp
inline auto & interval(
    double pd
)
```

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval) to accept a double argument. 

**Parameters**: 

  * **pd** interval as a double 


**Return**: reference to self 

#### function no_tty

```cpp
inline auto & no_tty()
```

Enable no-tty mode. 

**Return**: reference to self 

### Protected Functions Documentation

#### function render_progress_bar_

```cpp
inline size_t render_progress_bar_(
    std::ostream & out
)
```

Compute the shape of the progress bar based on progress and write to output stream. 

#### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```

Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total. 

#### function render_percentage_

```cpp
inline size_t render_percentage_(
    std::ostream & out
)
```

Write the percent completed to output stream. 

#### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function init

```cpp
inline void init(
    Progress * progress
)
```


#### function ProgressBar

```cpp
inline ProgressBar(
    std::ostream & out =std::cout
)
```


-------------------------------



## barkeep::Speedometer


Helper class to measure and display speed of progress.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream & out, [const](api/Classes/classbarkeep_1_1_counter.md) std::string & speed_unit)<br>Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed.  |
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

#### function render_speed

```cpp
inline size_t render_speed(
    std::ostream & out,
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

Updated on 2023-12-02 at 13:34:20 -0500