# barkeep::Composite




Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > left, std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > right) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([const](api/Classes/classbarkeep_1_1_counter.md)[Composite](api/Classes/classbarkeep_1_1_composite.md) & other) |
| | **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) && other) =default |
| | **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_composite.md#function-no_tty)**() |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**(std::ostream & out) override |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[left_](api/Classes/classbarkeep_1_1_composite.md#variable-left_)**  |
| std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[right_](api/Classes/classbarkeep_1_1_composite.md#variable-right_)**  |


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
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**() |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[message](api/Classes/classbarkeep_1_1_async_display.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**(Duration pd) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[interval](api/Classes/classbarkeep_1_1_async_display.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd) |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>


## Public Functions Documentation

### function Composite

```cpp
inline Composite(
    std::unique_ptr< AsyncDisplay > left,
    std::unique_ptr< AsyncDisplay > right
)
```


### function Composite

```cpp
inline Composite(
    constComposite & other
)
```


### function Composite

```cpp
Composite(
    Composite && other
) =default
```


### function ~Composite

```cpp
inline ~Composite()
```


### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### function no_tty

```cpp
inline auto & no_tty()
```


## Protected Functions Documentation

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


## Protected Attributes Documentation

### variable left_

```cpp
std::unique_ptr< AsyncDisplay > left_;
```


### variable right_

```cpp
std::unique_ptr< AsyncDisplay > right_;
```


-------------------------------

Updated on 2023-12-01 at 22:33:53 -0500