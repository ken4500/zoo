<GameProjectFile>
  <PropertyGroup Type="Layer" Name="Shop" ID="7ebcafc8-b3fc-44e0-a212-d639e3e6db5b" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CustomClassName="Shop" Tag="114" ctype="GameLayerObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="menu" ActionTag="-1252097155" Tag="150" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="68.0000" RightMargin="68.0000" TopMargin="-40.2080" BottomMargin="20.2080" ctype="SpriteObjectData">
            <Size X="1000.0000" Y="660.0000" />
            <Children>
              <AbstractNodeData Name="lineup" ActionTag="-779193947" Tag="67" IconVisible="False" LeftMargin="199.3994" RightMargin="408.6006" TopMargin="137.1077" BottomMargin="437.8923" LabelText="ラインナップ" ctype="TextBMFontObjectData">
                <Size X="392.0000" Y="85.0000" />
                <AnchorPoint ScaleY="0.5000" />
                <Position X="199.3994" Y="480.3923" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.1994" Y="0.7279" />
                <PreSize X="0.3920" Y="0.1414" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="line_1" ActionTag="-2112867300" Tag="66" IconVisible="False" LeftMargin="185.0181" RightMargin="178.9819" TopMargin="208.4418" BottomMargin="441.5582" ctype="SpriteObjectData">
                <Size X="636.0000" Y="10.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="503.0181" Y="446.5582" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5030" Y="0.6766" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ui/line.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="diamond_1" ActionTag="1178094178" Tag="219" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="494.3787" RightMargin="333.6213" TopMargin="59.3495" BottomMargin="452.6505" ctype="SpriteObjectData">
                <Size X="172.0000" Y="148.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="580.3787" Y="452.6505" />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5804" Y="0.6858" />
                <PreSize X="0.1720" Y="0.2463" />
                <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="hasDiamondNum" ActionTag="-1200641410" Tag="220" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="583.6619" RightMargin="220.3381" TopMargin="124.6335" BottomMargin="454.3665" LabelText="x 0000" ctype="TextBMFontObjectData">
                <Size X="196.0000" Y="81.0000" />
                <AnchorPoint ScaleX="1.0000" />
                <Position X="779.6619" Y="454.3665" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7797" Y="0.6884" />
                <PreSize X="0.1960" Y="0.1227" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="title" ActionTag="-420158703" Tag="151" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="370.0000" RightMargin="370.0000" TopMargin="52.7580" BottomMargin="526.2420" LabelText="ショップ" ctype="TextBMFontObjectData">
                <Size X="260.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="500.0000" Y="566.7420" />
                <Scale ScaleX="0.6000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8587" />
                <PreSize X="0.2600" Y="0.1227" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="offenseUp" ActionTag="528517738" Tag="152" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="208.4570" RightMargin="791.5430" TopMargin="255.0879" BottomMargin="404.9121" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="2108392878" Tag="153" IconVisible="False" LeftMargin="502.9968" RightMargin="-800.9968" TopMargin="-50.0001" BottomMargin="-49.9999" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-466018773" Tag="154" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-705016769" Tag="155" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.9968" Y="0.0001" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="currentValue" ActionTag="-1489364097" Tag="160" IconVisible="False" LeftMargin="401.9997" RightMargin="-463.9997" TopMargin="-3.7501" BottomMargin="-20.2499" FontSize="20" LabelText="1.0→" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="52.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="1.0000" />
                    <Position X="463.9997" Y="-20.2499" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="60" G="30" B="10" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="472686781" Tag="156" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="464.0048" RightMargin="-636.0048" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="464.0048" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-767279310" Tag="157" IconVisible="False" LeftMargin="0.0001" RightMargin="-257.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="動物の攻撃力アップ" ctype="TextBMFontObjectData">
                    <Size X="257.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="208.4570" Y="404.9121" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2085" Y="0.6135" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="spawnNum" ActionTag="-70746800" Tag="158" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="208.4570" RightMargin="791.5430" TopMargin="404.4958" BottomMargin="255.5042" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="195251998" Tag="159" IconVisible="False" LeftMargin="502.2506" RightMargin="-800.2506" TopMargin="-50.0001" BottomMargin="-49.9999" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-1871963264" Tag="160" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-1440329710" Tag="161" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.2506" Y="0.0001" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="1413115161" Tag="162" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="464.0043" RightMargin="-570.0043" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="2匹" ctype="TextBMFontObjectData">
                    <Size X="106.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="464.0043" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="651894491" Tag="163" IconVisible="False" LeftMargin="0.0001" RightMargin="-374.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="ツボから出る動物の数アップ" ctype="TextBMFontObjectData">
                    <Size X="374.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="0.9000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="currentValue" ActionTag="-1164170160" Tag="161" IconVisible="False" LeftMargin="401.9997" RightMargin="-463.9997" TopMargin="-3.7501" BottomMargin="-20.2499" FontSize="20" LabelText="1.0→" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="52.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="1.0000" />
                    <Position X="463.9997" Y="-20.2499" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="60" G="30" B="10" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="208.4570" Y="255.5042" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2085" Y="0.3871" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="animalNum" ActionTag="-475703228" Tag="164" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="208.4570" RightMargin="791.5430" TopMargin="354.7146" BottomMargin="305.2854" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="649164083" Tag="165" IconVisible="False" LeftMargin="502.2506" RightMargin="-800.2506" TopMargin="-49.9998" BottomMargin="-50.0002" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-1403824263" Tag="166" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="834987645" Tag="167" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.2506" Y="-0.0002" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="7410351" Tag="168" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="464.0043" RightMargin="-602.0043" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="21匹" ctype="TextBMFontObjectData">
                    <Size X="138.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="464.0043" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-1193281071" Tag="169" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="0.0000" RightMargin="-344.0000" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="保持できる動物の数アップ" ctype="TextBMFontObjectData">
                    <Size X="344.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="currentValue" ActionTag="1788391901" Tag="162" IconVisible="False" LeftMargin="401.9997" RightMargin="-463.9997" TopMargin="-3.7500" BottomMargin="-20.2500" FontSize="20" LabelText="1.0→" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="52.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="1.0000" />
                    <Position X="463.9997" Y="-20.2500" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="60" G="30" B="10" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="208.4570" Y="305.2854" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2085" Y="0.4626" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="getCoin" ActionTag="870292953" Tag="170" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="208.4570" RightMargin="791.5430" TopMargin="304.9339" BottomMargin="355.0661" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1000277048" Tag="171" IconVisible="False" LeftMargin="502.2506" RightMargin="-800.2506" TopMargin="-50.0001" BottomMargin="-49.9999" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-855150752" Tag="172" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-149824275" Tag="173" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.2506" Y="0.0001" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-305455982" Tag="174" IconVisible="False" LeftMargin="464.0048" RightMargin="-636.0048" TopMargin="-40.5002" BottomMargin="-40.4998" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="464.0048" Y="0.0002" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-1578028345" Tag="175" IconVisible="False" RightMargin="-288.0000" TopMargin="-15.8864" BottomMargin="-19.1136" LabelText="コインの取得量アップ" ctype="TextBMFontObjectData">
                    <Size X="288.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position Y="-1.6136" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="currentValue" ActionTag="1093189673" Tag="163" IconVisible="False" LeftMargin="401.9997" RightMargin="-463.9997" TopMargin="-3.7501" BottomMargin="-20.2499" FontSize="20" LabelText="1.0→" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="52.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="1.0000" />
                    <Position X="463.9997" Y="-20.2499" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="60" G="30" B="10" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="208.4570" Y="355.0661" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2085" Y="0.5380" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="emergeEnemy" ActionTag="2139147446" Tag="176" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="208.4570" RightMargin="791.5430" TopMargin="452.1458" BottomMargin="207.8542" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1232556359" Tag="177" IconVisible="False" LeftMargin="502.2506" RightMargin="-800.2506" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="320712365" Tag="178" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="-1807709403" Tag="179" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.2506" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="-2121557404" Tag="180" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="464.0048" RightMargin="-636.0048" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="1.5倍" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="464.0048" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="1622353508" Tag="181" IconVisible="False" LeftMargin="0.0001" RightMargin="-287.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="出現する敵の数アップ" ctype="TextBMFontObjectData">
                    <Size X="287.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="currentValue" ActionTag="-2035373453" Tag="164" IconVisible="False" LeftMargin="401.9997" RightMargin="-463.9997" TopMargin="-3.7500" BottomMargin="-20.2500" FontSize="20" LabelText="1.0→" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="52.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="1.0000" />
                    <Position X="463.9997" Y="-20.2500" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="60" G="30" B="10" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="208.4570" Y="207.8542" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2085" Y="0.3149" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="okButton" ActionTag="-993402210" Tag="182" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="399.9999" RightMargin="400.0001" TopMargin="568.1120" BottomMargin="-28.1120" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="275" Scale9Height="112" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="200.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="coinLabel_0" ActionTag="199476714" Tag="183" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="45.0000" RightMargin="45.0000" TopMargin="19.5000" BottomMargin="19.5000" LabelText="OK" ctype="TextBMFontObjectData">
                    <Size X="110.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="100.0000" Y="60.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5000" />
                    <PreSize X="0.5500" Y="0.6750" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="499.9999" Y="31.8880" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.0483" />
                <PreSize X="0.2000" Y="0.1997" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="maxLife" ActionTag="-1653187990" Tag="64" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="208.2187" RightMargin="791.7813" TopMargin="498.4654" BottomMargin="161.5346" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1720649083" Tag="65" IconVisible="False" LeftMargin="502.2498" RightMargin="-800.2498" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="diamond" ActionTag="-454444690" Tag="66" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="-4.6726" RightMargin="130.6726" TopMargin="-24.0000" BottomMargin="-24.0000" ctype="SpriteObjectData">
                        <Size X="172.0000" Y="148.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="81.3274" Y="50.0000" />
                        <Scale ScaleX="0.4500" ScaleY="0.4500" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.2729" Y="0.5000" />
                        <PreSize X="0.5772" Y="1.4800" />
                        <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                        <BlendFunc Src="1" Dst="771" />
                      </AbstractNodeData>
                      <AbstractNodeData Name="requreNum" ActionTag="1627235019" Tag="67" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="129.6968" RightMargin="36.3032" TopMargin="9.5000" BottomMargin="9.5000" LabelText="x 10" ctype="TextBMFontObjectData">
                        <Size X="132.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="195.6968" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.6567" Y="0.5000" />
                        <PreSize X="0.4430" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.2498" Y="0.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="nextValue" ActionTag="1084290808" Tag="68" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="464.3017" RightMargin="-572.3017" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="3個" ctype="TextBMFontObjectData">
                    <Size X="108.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="464.3017" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-87818536" Tag="69" IconVisible="False" LeftMargin="0.0001" RightMargin="-231.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="最大ライフアップ" ctype="TextBMFontObjectData">
                    <Size X="231.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="currentValue" ActionTag="1950950741" Tag="165" IconVisible="False" LeftMargin="402.2977" RightMargin="-464.2977" TopMargin="-3.7501" BottomMargin="-20.2499" FontSize="20" LabelText="1.0→" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                    <Size X="52.0000" Y="20.0000" />
                    <AnchorPoint ScaleX="1.0000" />
                    <Position X="464.2977" Y="-20.2499" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="60" G="30" B="10" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="208.2187" Y="161.5346" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2082" Y="0.2447" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
              <AbstractNodeData Name="buyDiamond" ActionTag="189743508" Tag="70" IconVisible="True" PositionPercentYEnabled="True" LeftMargin="209.2183" RightMargin="790.7817" TopMargin="543.4658" BottomMargin="116.5342" ctype="SingleNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <Children>
                  <AbstractNodeData Name="button" ActionTag="-1123262411" Tag="71" IconVisible="False" LeftMargin="502.2512" RightMargin="-800.2512" TopMargin="-50.0000" BottomMargin="-50.0000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="268" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                    <Size X="298.0000" Y="100.0000" />
                    <Children>
                      <AbstractNodeData Name="requreNum" ActionTag="-1206245480" Tag="73" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="58.1949" RightMargin="66.8051" TopMargin="9.5000" BottomMargin="9.5000" LabelText="￥120" ctype="TextBMFontObjectData">
                        <Size X="173.0000" Y="81.0000" />
                        <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                        <Position X="144.6949" Y="50.0000" />
                        <Scale ScaleX="1.0000" ScaleY="1.0000" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <PrePosition X="0.4856" Y="0.5000" />
                        <PreSize X="0.5805" Y="0.8100" />
                        <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                      </AbstractNodeData>
                    </Children>
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="651.2512" Y="0.0000" />
                    <Scale ScaleX="0.5000" ScaleY="0.5000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <TextColor A="255" R="65" G="65" B="70" />
                    <DisabledFileData Type="Normal" Path="ui/button03_disable.png" Plist="" />
                    <PressedFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <NormalFileData Type="Normal" Path="ui/button03.png" Plist="" />
                    <OutlineColor A="255" R="255" G="0" B="0" />
                    <ShadowColor A="255" R="110" G="110" B="110" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="value" ActionTag="-530508670" Tag="74" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="453.0560" RightMargin="-625.0560" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="200個" ctype="TextBMFontObjectData">
                    <Size X="172.0000" Y="81.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="453.0560" />
                    <Scale ScaleX="0.6000" ScaleY="0.6000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="diamond" ActionTag="-1573357720" Tag="76" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="336.9998" RightMargin="-508.9998" TopMargin="-74.0000" BottomMargin="-74.0000" ctype="SpriteObjectData">
                    <Size X="172.0000" Y="148.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="422.9998" />
                    <Scale ScaleX="0.3000" ScaleY="0.3000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.5772" Y="1.4800" />
                    <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                    <BlendFunc Src="1" Dst="771" />
                  </AbstractNodeData>
                  <AbstractNodeData Name="description" ActionTag="-1335030474" Tag="75" IconVisible="False" LeftMargin="0.0001" RightMargin="-260.0001" TopMargin="-17.5000" BottomMargin="-17.5000" LabelText="ダイヤモンド200個" ctype="TextBMFontObjectData">
                    <Size X="260.0000" Y="35.0000" />
                    <AnchorPoint ScaleY="0.5000" />
                    <Position X="0.0001" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition />
                    <PreSize X="0.0000" Y="0.0000" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font5.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint />
                <Position X="209.2183" Y="116.5342" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2092" Y="0.1766" />
                <PreSize X="0.0000" Y="0.0000" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="350.2080" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5472" />
            <PreSize X="0.8803" Y="0.9391" />
            <FileData Type="Normal" Path="ui/menu5.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>